//tianxiang_gao.h

//Sample for ITEM ���������
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CItianxiang_gao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���������");	//set item name

	set("unit", "��");
	set("long", "����һ�к�ɫ�����˸�ҩ�����Բ�Ϳ��smear����");

};
virtual int do_use(CChar * me, CContainer * target)
{
     if ( me->query("eff_hp") >= me->query("max_hp") )
	 {
		 tell_object(me,"��ʲô��������û���ˣ��ò���Ϳ����");
		 return 0;
	 }
	 me->set_temp("nopoison", 1);
	 me->receive_curing("hp",250);
	 tell_object(me, "��Ѻ�ɫ�ĸ�ҩͿ�����˿��ϣ���ʱ����һ������֮������ȫ��"  );
	 destruct(this);
     return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp