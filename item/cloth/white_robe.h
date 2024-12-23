EQUIP_BEGIN(CIwhite_robe);

virtual void create(int nFlag = 0)	
{
	set_name( "白色道袍");

	set("wield_position", WIELD_ARMOR);		
 	set_weight(4500);		
        set("value", 300);
	set("unit", "件");
	set("long", "这是件素雅洁净的白色道袍。");
	set("material", "cloth");
	set("apply/armor", 3);
};

EQUIP_END;
