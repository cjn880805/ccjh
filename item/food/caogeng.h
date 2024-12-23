FOOD_BEGIN(CIcaogeng);

virtual void create(int nFlag = 0)	
{
	set_name( "草根");	

	set_weight(2000);
	
	set("unit", "堆");
	set("value", 10);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->receive_damage("hp", random(250)+1);

	char msg[255];
	snprintf(msg, 255, "%s吃下一堆草根，肚子咕嘟咕嘟的叫了半天。", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;




