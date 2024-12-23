// 灵袄
// Lanwood 2001-03-22

EQUIP_BEGIN(CIlingao);

virtual void create(int nFlag = 0)
{
        set_name("灵袄", "ling ao");
        set_weight(1000);
    
		set("wield_position", WIELD_ARMOR);

        set("unit", "件");
		set("long", "灵蓝为子陵精心缝制的棉袄。");
        set("value", 100);
		
		set("apply/attack", 50);
		set("apply/defense", 50);

		set("apply/damage", 20);
		set("apply/armor", 150);

		set("apply/str", 3);
		set("apply/dex", 3);
		set("apply/int", 3);

		set("apply/per", 10);

		set("owner", "740");

		set("no_sell", 1);

		set("wield_msg", "$N穿上一件$n，似乎又回想起灵蓝老婆的好处来……");
		set("unwield_msg", "$N脱下一件$n，细心藏好。");
}

EQUIP_END;