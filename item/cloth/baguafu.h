
EQUIP_BEGIN(CIbaguafu);


virtual void create(int nFlag = 0)		
{
	set_name( "八卦服");

	set("wield_position", WIELD_ARMOR);		
 	set_weight(2000);		

	set("long", "这是八卦弟子练功服。");
	set("material", "cloth");
	set("unit", "件");
	set("value", 200);
	set("apply/armor", 50);
};

EQUIP_END;
