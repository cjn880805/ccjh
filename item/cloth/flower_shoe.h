//flower_shoe �廨СЬ
EQUIP_BEGIN(CIflower_shoe);

virtual void create(int nFlag = 0)	
{
	set_name( "�廨СЬ",  "flower shoes");
	set("wield_position", WIELD_BOOT);	

	set_weight(900);

	set("material", "cloth");
	set("unit", "˫");
	set("value", 300);
	set("apply/armor", 1 );
	set("female_only", 1);
};

EQUIP_END;
