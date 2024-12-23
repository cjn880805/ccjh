//zhuguo.h

//Sample for ITEM ���
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzhuguo);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���");	//set item name

	set_weight(20);

	set("unit", "��");
	set("long","����һ�������ͨ���ʺ죬һ����֪�ǲ��ɶ�õ���Ʒ��");
	set("value", 1000);

//	set("no_get", "�ٺ٣����ΰ�! ");
//	set("no_drop","����㶼���ӣ�");
	
};
virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	if(!me->query_temp("pro/z_hp") && !me->query_temp("pro/hp")&& !me->query_temp("pro5/hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")*2);
		me->set("hp", me->query_temp("max_hp")*2);
		me->set("eff_hp", me->query_temp("max_hp")*2);
		me->set_temp("pro/hp",1);
		me->UpdateMe();
	}
	else if(me->query_temp("pro/hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")/2);
		me->set("hp", me->query_temp("max_hp")/2);
		me->set("eff_hp", me->query_temp("max_hp")/2);
		me->delete_temp("pro/hp");
		me->UpdateMe();
	}
	snprintf(msg, 255, "%s����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp