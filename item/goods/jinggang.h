//���ħ��
//jing_gang.h
//2001-03-26

ITEM_BEGIN(CIjing_gang);

virtual void create(int nFlag = 0)		
{
	set_name("���ħ��", "jing_gang");
	set("value", 1);
	set("weight", 100);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	me->add("mp", -50);
	if(me->query("level")>=80 && me->query("food/jing_gang")<100)
	{
		message_vision("$YEL$N�ͳ�һ�Ž��ħ�䣬����ߴ�ﹾ���һ�����üͷ������˲��һ�����ƺ�������Щʲô��", me);
		me->add("combat_exp", 3000);
		me->add("repute",-3000);
		me->add("food/jing_gang",1);
		me->FlushMyInfo();
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)ʹ���˽��ħ�䣬�ۼ�ʹ����%ld�ν��ħ��!", me->name(1), me->id(1), me->query("food/jing_gang")));
	}
	else
	{
		message_vision("$YEL$N�ͳ�һ�Ž��ħ�䣬����ߴ�ﹾ���һ���������ֻ��$N������ͷ��ȴ��֪���ƣ����ɺ��ô�Ц��", me);
	}
	destruct(this);
	return 1; 
}

ITEM_END;




