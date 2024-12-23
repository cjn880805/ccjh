//yaoshi.h
ITEM_BEGIN(CIyaoshi)

virtual void create(int nFlag = 0)		
{
	set_name("牢房钥匙", "laofang key");
	set("long",	"这是一把很普通的钥匙。");
	set("unit", "把");
	set_weight(1);
};

ITEM_END;
