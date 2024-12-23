FOOD_BEGIN(CIluobo);

virtual void create(int nFlag = 0)	
{
	set_name( "大萝卜");	

	set_weight(2000);
	
	set("unit", "个");
	set("value", 400);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->receive_curing("hp", random(random(250))+1);

	char msg[255];
	snprintf(msg, 255, "%s吃下一个大萝卜，肚子咕嘟咕嘟的叫了半天。", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;




