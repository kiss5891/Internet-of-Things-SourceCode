資料庫命名規則
資料表名稱 : 大駝峰式 + 結尾加s
	EX ： HelloWord  

預存程序 (Stored procedures)
	sp<App Name>_[<Group Name >_]<Action><table/logical instance>
	sp<應用程式名稱>_[<群組名稱>_]<動作><table/logical instance>
	EX : spHello_Word

觸發程序 (Triggers)
	TR_<TableName>_<action>
	TR_<資料表名稱>_<動作>
	EX : TR_HelloWord

 索引(Index)
	IX_<TableName>_<columns separated by _>
	IX_<資料表名稱>_<欄位名稱>
 	EX : IX_HelloWorld

   說明:IX開頭、底線、接資料表名、底線、接欄位名

 

主索引鍵(Primary Key)
	PK_<TableName>
	PK_<資料表名稱>
	EX : PK_Hello

 

外部索引建(Foreign Key)
	FK_<TableName1>_<TableName2>
	FK_<資料庫A>_<資料庫B>
  	EX : FK_Hello_World

預設值(Default)
	DF_<TableName>_<ColumnName>
	DF_<資料表名稱>_<欄位>
	EX： DF_Hello_Value


