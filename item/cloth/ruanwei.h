//ruanwei.h 软猬甲

EQUIP_BEGIN(CIruanwei);

virtual void create(int nFlag = 0)	
{
	set_name( "软猬甲", "ruanwei jia");
    set_weight(1000);

	set("wield_position", WIELD_ARMOR);	

	set("unit", "件");
    set("long", "一件轻飘飘的、生满尖锐倒刺的护甲。");
	set("material", "copper");
	set("value",2000);
	set("no_drop", "这样东西不能离开你。");
	set("no_get", "这样东西不能离开那儿。");
	set("apply/armor", 75);
	set("apply/dodge", -5);
};

EQUIP_END;
