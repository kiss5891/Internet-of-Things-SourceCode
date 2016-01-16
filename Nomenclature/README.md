#資料庫命名規則
##資料表名稱 : 大駝峰式 + 結尾加s
	EX ： Lockers

##預存程序 (Stored procedures)
	sp<App Name>_[<Group Name >_]<Action><table/logical instance>
	sp<應用程式名稱>_[<群組名稱>_]<動作><table/logical instance>
	EX : spLockers_Admin_Add
	沒有特別去選擇就會優先去執行

##觸發程序 (Triggers)
	TR_<TableName>_<action>
	TR_<資料表名稱>_<動作>
	EX : TR_Lockers_Add
	當Lockers資料表做刪除的動作時就會去執行

##索引(Index)
	IX_<TableName>_<columns separated by _>
	IX_<資料表名稱>_<欄位名稱>
 	EX : IX_Lockers_ID
	給一個欄位索引可以加速所尋該欄位的速度

##主索引鍵(Primary Key)
	PK_<TableName>
	PK_<資料表名稱>
	EX : PK_Lockers
	索引的值不會重複像是身份證

 ##外部索引建(Foreign Key)
	FK_<TableName1>_<TableName2>
	FK_<資料庫A>_<資料庫B>
  	EX : FK_Users_Companys
	可以從Users的資料庫找到Companys資料庫的值

##預設值(Default)
	DF_<TableName>_<ColumnName>
	DF_<資料表名稱>_<欄位>
	EX： DF_Goods_GoodsNumber
	預設物品編號


