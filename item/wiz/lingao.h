// ���
// Lanwood 2001-03-22

EQUIP_BEGIN(CIlingao);

virtual void create(int nFlag = 0)
{
        set_name("���", "ling ao");
        set_weight(1000);
    
		set("wield_position", WIELD_ARMOR);

        set("unit", "��");
		set("long", "����Ϊ���꾫�ķ��Ƶ��ް���");
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

		set("wield_msg", "$N����һ��$n���ƺ��ֻ������������ŵĺô�������");
		set("unwield_msg", "$N����һ��$n��ϸ�Ĳغá�");
}

EQUIP_END;