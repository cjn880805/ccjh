//hanshuang_miji.h 
//code by sound
//2001-12-10
//ȡ�ú�˪�ؼ�

ITEM_BEGIN(CIhanshuang_miji);

virtual void create(int nFlag = 0)		
{
	static struct{
		char name[20];
		char id[20];
	} miji[9] = {
		{"��˪�ܼ���һ��ƪ", "hanshuang miji1",},
		{"��˪�ܼ��ڶ���ƪ", "hanshuang miji2",},
		{"��˪�ܼ�������ƪ", "hanshuang miji3",},
		{"��˪�ܼ����Ĳ�ƪ", "hanshuang miji4",},
		{"��˪�ܼ������ƪ", "hanshuang miji5",},
		{"��˪�ܼ�������ƪ", "hanshuang miji6",},
		{"��˪�ܼ����߲�ƪ", "hanshuang miji7",},
		{"��˪�ܼ��ڰ˲�ƪ", "hanshuang miji8",},
		{"��˪�ܼ��ھŲ�ƪ", "hanshuang miji9",},
	};

	int lvl = random(9);

	if(nFlag) lvl = nFlag - 1;

	set_name( miji[lvl].name, miji[lvl].id);
	set_weight(0l);	
	set("unit", "ƪ");
	set("long","��˵����ܹ����Ͼ�ƪ��˪�ؼ��Ĳ�ƪ������ѧ�����еľ���������");
};

virtual int do_look(CChar * me)
{
	say("�������ƪ���˿��������������д�ж����������뿴���һ��ʱȴ����ʲô��û�С�",me);
	say("��˵����ܹ��ռ�����ƪ��ͬ���ؼ���ƪ�����п���ѧ����˪������",me);
	AddMenuItem("��ϸ��","$0combine $1",me);
	AddMenuItem("����","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "combine") == 0)
		return do_combine(me, arg);
	return 0;
}

int do_combine(CChar *me, char * arg)
{
	char msg[255];
	
	CContainer * miji1;
	miji1=me->present("hanshuang miji1");
	
	CContainer * miji2;
	miji2=me->present("hanshuang miji2");
	
	CContainer * miji3;
	miji3=me->present("hanshuang miji3");
	
	CContainer * miji4;
	miji4=me->present("hanshuang miji4");
	
	CContainer * miji5;
	miji5=me->present("hanshuang miji5");
	
	CContainer * miji6;
	miji6=me->present("hanshuang miji6");
	
	CContainer * miji7;
	miji7=me->present("hanshuang miji7");
	
	CContainer * miji8;
	miji8=me->present("hanshuang miji8");
	
	CContainer * miji9;
	miji9=me->present("hanshuang miji9");
	
	if (miji1)
		tell_object(me,"ƴ�ϵ�һƪ��ƪ");
	if (miji2)
		tell_object(me,"ƴ�ϵڶ�ƪ��ƪ");
	if (miji3)
		tell_object(me,"ƴ�ϵ���ƪ��ƪ");
	if (miji4)
		tell_object(me,"ƴ�ϵ���ƪ��ƪ");
	if (miji5)
		tell_object(me,"ƴ�ϵ���ƪ��ƪ");
	if (miji6)
		tell_object(me,"ƴ�ϵ���ƪ��ƪ");
	if (miji7)
		tell_object(me,"ƴ�ϵ���ƪ��ƪ");
	if (miji8)
		tell_object(me,"ƴ�ϵڰ�ƪ��ƪ");
	if (miji9)
		tell_object(me,"ƴ�ϵھ�ƪ��ƪ");

	if (miji1 && miji2 && miji3 && miji4 && miji5 && miji6 && miji7 && miji8 && miji9)
	{
		destruct(miji1);
		destruct(miji2);
		destruct(miji3);
		
		destruct(miji4);
		destruct(miji5);
		destruct(miji6);
		
		destruct(miji7);
		destruct(miji8);
		destruct(miji9);
		
		message_vision("$HIC��Ȼ������Щ��ƪ�ƺ���������һ���㼱æ��ϸ�ۿ�����$COM",me);
		message_vision("$HIC�����ڰ���Щ��ƪƴ����һ��Ȼ���ý���������ճ�ϡ���$COM",me);

		int i, j, skill, lvl;

		skill = me->query_skill("frost_blade", 1);

		lvl = me->query("level");
		
		if (lvl < 80)
		{
			lvl = 80;
		}

		i = lvl - 79;
		j = random(i);

		if (j == 0)
		{
			tell_object(me,"$HIY��ϲ��õ��˺�˪������ѧ��$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s$HIY�ڵ�������ñ��أ�ѧ���˺�˪������\n\n$COM", me->name(1)));
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѧ���˺�˪������", me->name(1)));
			me->set_skill("frost_blade", skill + 1);
		}
		
		else
		{
			tell_object(me,"$HIYͻȻ$N��ɫ$HIR����$HIY��������ѣ��ԭ��$N��С�İѲ�ƪ˺�ƣ�ֻʣ��һ����Ƭ��$COM");
		}

		return 1;
	}
	
	tell_object(me,"�����Щ��ƪ��ƴ��ƴ����ʲô��ûƴ������");
	return 1;
	
}

ITEM_END;








