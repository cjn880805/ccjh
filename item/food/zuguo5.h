//zuguo.h ���

FOOD_BEGIN(CIzuguo5);

virtual void create(int nFlag = 0)		
{
	set_name( "���","zu guo");	

	set_weight(20);
	set("unit", "��");
	set("value", 30000000);
	set("long","����һ�������ͨ���ʺ죬һ����֪�ǲ��ɶ�õ��˼���Ʒ��");
};

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	if(!me->query_temp("pro/z_hp") && !me->query_temp("pro/hp")&& !me->query_temp("pro5/hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")*5);
		me->set("hp", me->query("max_hp"));
		me->set("eff_hp", me->query("max_hp"));
		me->set_temp("pro5/z_hp",1);
		me->UpdateMe();
	}
	else if(me->query_temp("pro5/z_hp"))
	{
		me->set("max_hp", me->query_temp("max_hp")/5);
		me->set("hp", me->query("max_hp"));
		me->set("eff_hp", me->query("max_hp"));
		me->delete_temp("pro5/z_hp");
		me->UpdateMe();
	}
	snprintf(msg, 255, "%s����һ�������ֻ������ȫ����һ��ů���ӵ���ֱ��������", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}



FOOD_END;
//last, register the item into ../server/ItemSetup.cpp