FOOD_BEGIN(CIluobo);

virtual void create(int nFlag = 0)	
{
	set_name( "���ܲ�");	

	set_weight(2000);
	
	set("unit", "��");
	set("value", 400);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->receive_curing("hp", random(random(250))+1);

	char msg[255];
	snprintf(msg, 255, "%s����һ�����ܲ������ӹ�ཹ�ཱུĽ��˰��졣", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;



