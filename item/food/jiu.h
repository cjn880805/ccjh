//jiu.h

//Sample for ITEM �����̻��
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjiu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����̻��");	//set item name
  
	set("unit", "��");
	set("long", "����һ�����֮���������̻�ƣ���˵�ܽ�ٶ���");
	set("value", 200);


};

virtual int do_use(CChar * me, CContainer * target)
{
	me->set_temp("nopoison", 1);
	me->set("eff_hp",me->query("max_hp"));
	me->set("hp",me->query("max_hp"));
	tell_object(me,  "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��"  );
	destruct(this );
	return 1;

}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp