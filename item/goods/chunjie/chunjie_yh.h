//chunjie_yh.h
ITEM_BEGIN(CIchunjie_yh)

virtual void create(int nFlag = 0)		
{
	set_name("�̻�", "yan hua");
	set("long",	"����һ֧����ʱʹ�õ��̻���������֧�̻����ر�Ŷ��");
	set("unit", "��");
	set_weight(10);
	set("value", 1);
	
	call_out(do_die, 3600);	

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * who)
{
	if(who == me)
	{
		char msg[512];
		int i,index;
		CContainer * env=me->environment();
		g_Channel.do_channel(&g_Channel, 0, "news", 
				snprintf(msg, 512, "\n\n               $HIR%s(%s)$HIW���е��̻���Ϊһ���⣬ֱ������ʡ�\n               ��ʵĹ�Ӱ�Կ���ɢ�����û�������������ͼ����\n                         ������������ͬ�죡\n                    ��Ӱ��Ũ������Ϊ���������Ĵ��֣�\n                $HIR%s(%s)��ף����ȫ������������֡��������⣡$HIW\n          ���ã�ֻ��һ������Ʈ�����������컨�꣬�м仹�����ż������Ķ���֮�죬������׹�̡�\n\n",
				me->name(1),me->id(1),me->name(1),me->id(1)));

		for(i=0;i<random(4)+2;i++)
			load_item("huaban")->move(env);
		tell_room(env,"����Ļ����������������");

		for(i=0;i<random(4)+2;i++)
			load_item("zhenzhu")->move(env);
		tell_room(env,"˶��������������������");

		for(i=0;i<random(4)+1;i++)
		{
			index=random(MAX_ROOM_NUM);
			env = load_room(global_room_name[index]);
			load_item("huaban")->move(env);
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "�����ƶ�����%s��",env->querystr("base_name")));
			tell_room(env,"����Ļ����������������");
		}
		for(i=0;i<random(2)+1;i++)
		{
			index=random(MAX_ROOM_NUM);
			env = load_room(global_room_name[index]);
			load_item("zhenzhu")->move(env);
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "�������ƶ�����%s��",env->querystr("base_name")));
			tell_room(env,"˶��������������������");
		}
		destruct(this);
		return 1;
	}

	return notify_fail("�̻����ܶԱ���ʹ�á�");
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;

	if(month>=2)
	{
		CContainer * env = load_room("jy");
		if(!env->query("�"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);

}
ITEM_END;
