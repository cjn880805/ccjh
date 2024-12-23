//anmenkey.h
ITEM_BEGIN(CIanmenkey)

virtual void create(int nFlag = 0)		
{
	set_name("暗门钥匙", "anmenkey");
	set("long",	"这是一把金钥匙。");
	set("unit", "把");
	set_weight(10);
	set("value", 10000);

};

ITEM_END;
