//chunjie_ts.h ��ʫ������
//�ز� 2002-03-26

EQUIP_BEGIN(CIchunjie_ts);

virtual void create(int nFlag = 0)	
{
	set_name( "��ʫ������");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set_weight(1000);		//set item weight
	
	set("unit", "��");
	set("long", "һ�������ƴ��ڶ�ʫ��������Ѫ֮����ʫ���������Ķ�����ʹ�����ѧ��Ϊ�õ�������");
	set("value", 1);
	set("apply/int",10);

};

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
} 

EQUIP_END;



