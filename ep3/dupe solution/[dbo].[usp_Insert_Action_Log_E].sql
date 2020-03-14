USE [PS_GameLog]
GO
/****** Object:  StoredProcedure [dbo].[usp_Insert_Action_Log_E]    Script Date: 3/14/2020 2:46:45 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROC [dbo].[usp_Insert_Action_Log_E]

@UserID varchar(18),
@UserUID int,
@CharID int,
@CharName nvarchar(50),
@CharLevel tinyint,
@CharExp int,
@MapID smallint,
@PosX real,
@PosY real,
@PosZ real,
@ActionTime datetime,
@ActionType tinyint,
@Value1 bigint = null,
@Value2 int = null,
@Value3 int = null,
@Value4 bigint = null,
@Value5 int = null,
@Value6 int = null,
@Value7 int = null,
@Value8 int = null,
@Value9 int = null,
@Value10 int = null,
@Text1 varchar(100) = '',
@Text2 varchar(100) = '',
@Text3 varchar(100) = '',
@Text4 varchar(100) = '',
@Sql nvarchar(4000) = '',
@yyyy varchar(4) = '',
@mm varchar(2) = '',
@dd varchar(2) = '',
@Bucket smallint = -1
	
AS

DECLARE @Leave BIT

SET @yyyy = DATEPART(yyyy, @ActionTime)
SET @mm = DATEPART(mm, @ActionTime)
SET @dd = DATEPART(dd, @ActionTime)

IF(LEN(@mm) = 1)
BEGIN
	SET @mm = '0' + @mm
END

IF(LEN(@dd) = 1)
BEGIN
	SET @dd = '0' + @dd
END

IF @ActionType = 116 -- item transaction
BEGIN
	WAITFOR DELAY '00:00:05' -- wait 5 seconds
	
	SET @Leave = (SELECT Leave FROM PS_UserData.dbo.Users_Master WHERE UserUID = @UserUID)
	-- if user is offline only 5 seconds after the transaction was completed,
	-- then they definitely duped, since a proper logout takes 10 seconds
	IF @Leave = 0
	BEGIN
		-- delete the item from the seller's inventory		
		DELETE FROM PS_GameData.dbo.CharItems
		WHERE ItemUID = @Value1 AND CharID = @CharID
	END
END

IF @ActionType = 164 -- money transaction
BEGIN	
	WAITFOR DELAY '00:00:05'
	
	SET @Leave = (SELECT Leave FROM PS_UserData.dbo.Users_Master WHERE UserUID = @UserUID)
	-- if user is offline only 5 seconds after the transaction was completed,
	-- then they definitely duped, since a proper logout takes 10 seconds
	IF @Leave = 0
	BEGIN
		-- remove the duped gold
		UPDATE PS_GameData.dbo.Chars
		SET [Money] = @Value2
		WHERE CharID = @CharID
	END	
END
    
SET @Sql = N'
INSERT INTO PS_GameLog.dbo.ActionLog (UserID, UserUID, CharID, CharName, CharLevel, CharExp, MapID, PosX, PosY, PosZ, 
ActionTime, ActionType, Value1, Value2, Value3, Value4, Value5, Value6, Value7, Value8, Value9, Value10, Text1, Text2, Text3, Text4)
VALUES (@UserID, @UserUID, @CharID, @CharName, @CharLevel, @CharExp, @MapID, @PosX, @PosY, @PosZ, @ActionTime, @ActionType, 
@Value1, @Value2, @Value3, @Value4, @Value5, @Value6, @Value7, @Value8, @Value9, @Value10, @Text1, @Text2, @Text3, @Text4)'

EXEC sp_executesql @Sql, 
N'@UserID varchar(18), @UserUID int, @CharID int, @CharName nvarchar(50), @CharLevel tinyint, @CharExp int, @MapID smallint, 
@PosX real, @PosY real, @PosZ real, @ActionTime datetime, @ActionType tinyint, @Value1 bigint, @Value2 int, @Value3 int, @Value4 bigint, 
@Value5 int, @Value6 int, @Value7 int, @Value8 int, @Value9 int, @Value10 int, @Text1 varchar(100), @Text2 varchar(100), @Text3 varchar(100), @Text4 varchar(100)',
@UserID, @UserUID, @CharID, @CharName, @CharLevel, @CharExp, @MapID, @PosX, @PosY, @PosZ, @ActionTime, @ActionType, 
@Value1, @Value2, @Value3, @Value4, @Value5, @Value6, @Value7, @Value8, @Value9, @Value10, @Text1, @Text2, @Text3, @Text4