//shudai.h �������

EQUIP_BEGIN(CIshudai);

virtual void create(int nFlag = 0)	
{
	set_name( "�������", "jindai");
    set_weight(50);

	set("wield_position", WIELD_HEAD);	

	set("unit", "��");
    set("long","����һ���ý�˿֯�ɵ���������");
    set("value", 1500);
    set("material", "silk");
	set("apply/per", 1);
    set("apply/armor", 1);
	set("female_only", 1);
    set("wear_msg", "$N��$n�ó�����ͷ���ϡ�");
};

EQUIP_END;
