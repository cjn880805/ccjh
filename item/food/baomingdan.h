//baomingdan.h ������

FOOD_BEGIN(CIbaomingdan);

virtual void create(int nFlag = 0)		
{
	set_name( "������");	
	set_weight(700);
	set("unit", "��");
	set("long", "���Ǵ�˵������ʿ��������Ĳ����ɵ�������ɫ���ʻƣ������ŵ����Ĺ��Σ�ʱ�������ƣ��������㡣");
};

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("kill/flee")<11)
	{
		if(me->query("kill/flee")>=me->query("kill/death"))
		{
			me->set("kill/flee", me->query("kill/flee")-me->query("kill/death")+1);
			me->del("kill/death");
		}
		message_vision("$HIR$N�����˱����𵤣���Ѹ�ٽ���$N���ڸ�����ɢ�����������뵤��������澭������\n$N�ľ����͵�һ�񣬹�ϲ��ϲ��$N��������츳���һ��������!", me);
	}
	destruct(this);
	return 1;

}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



