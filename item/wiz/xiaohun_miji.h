//xiaohun_miji.h 
//2001-12-10
//ȡ�������ؼ�

ITEM_BEGIN(CIxiaohun_miji);

virtual void create(int nFlag = 0)		
{
	static struct{
		char name[20];
		char id[20];
	} miji[12] = {
		{"�����ؼ���һ��ƪ", "xiaohun miji1",},
		{"�����ؼ��ڶ���ƪ", "xiaohun miji2",},
		{"�����ؼ�������ƪ", "xiaohun miji3",},
		{"�����ؼ����Ĳ�ƪ", "xiaohun miji4",},
		{"�����ؼ������ƪ", "xiaohun miji5",},
		{"�����ؼ�������ƪ", "xiaohun miji6",},
		{"�����ؼ����߲�ƪ", "xiaohun miji7",},
		{"�����ؼ��ڰ˲�ƪ", "xiaohun miji8",},
		{"�����ؼ��ھŲ�ƪ", "xiaohun miji9",},
		{"�����ؼ���ʮ��ƪ", "xiaohun miji10",},
		{"�����ؼ���ʮһ��ƪ", "xiaohun miji11",},
		{"�����ؼ���ʮ����ƪ", "xiaohun miji12",},
	};

	int lvl = random(12);

	if(nFlag) lvl = nFlag - 1;

	set_name( miji[lvl].name, miji[lvl].id);
	set_weight(0l);	
	set("unit", "ƪ");
	set("long","��˵����ܹ�����ʮ��ƪ�����ؼ��Ĳ�ƪ������ѧ�����еľ���������");
};

virtual int do_look(CChar * me)
{
	say("�������ƪ���˿��������������д�ж����������뿴���һ��ʱȴ����ʲô��û�С�",me);
	say("��˵����ܹ��ռ���ʮ��ƪ��ͬ���ؼ���ƪ�����п���ѧ�����꽣����",me);
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
	miji1=me->present("xiaohun miji1");
	
	CContainer * miji2;
	miji2=me->present("xiaohun miji2");
	
	CContainer * miji3;
	miji3=me->present("xiaohun miji3");
	
	CContainer * miji4;
	miji4=me->present("xiaohun miji4");
	
	CContainer * miji5;
	miji5=me->present("xiaohun miji5");
	
	CContainer * miji6;
	miji6=me->present("xiaohun miji6");
	
	CContainer * miji7;
	miji7=me->present("xiaohun miji7");
	
	CContainer * miji8;
	miji8=me->present("xiaohun miji8");
	
	CContainer * miji9;
	miji9=me->present("xiaohun miji9");

	CContainer * miji10;
	miji10=me->present("xiaohun miji10");

	CContainer * miji11;
	miji11=me->present("xiaohun miji11");

	CContainer * miji12;
	miji12=me->present("xiaohun miji12");
	
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
	if (miji10)
		tell_object(me,"ƴ�ϵ�ʮƪ��ƪ");
	if (miji11)
		tell_object(me,"ƴ�ϵ�ʮһƪ��ƪ");
	if (miji12)
		tell_object(me,"ƴ�ϵ�ʮ��ƪ��ƪ");

	if (miji1 && miji2 && miji3 && miji4 && miji5 && miji6 && miji7 && miji8 && miji9 && miji10 && miji11 && miji12)
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

		destruct(miji10);
		destruct(miji11);
		destruct(miji12);
		
		message_vision("$HIC��Ȼ������Щ��ƪ�ƺ���������һ���㼱æ��ϸ�ۿ�����$COM",me);
		message_vision("$HIC�����ڰ���Щ��ƪƴ����һ��Ȼ���ý���������ճ�ϡ���$COM",me);

		int i, j, skill, lvl;

		skill = me->query_skill("misssword", 1);

		lvl = me->query("level");
		
		if (lvl < 120)
		{
			j=0;
		}
		else
		{
			i = lvl - 119;
			j = random(i);
		}

		if (j>0  && EQUALSTR(me->querystr("gender"), "����") )
		{
			tell_object(me,"$HIY��ϲ��õ������꽣����ѧ��$COM");
			g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "\n\n$HIC%s%s$HIY���Թ��������ˣ�����ǧ������������ؼ������������꽣����\n\n$COM", me->querystr("family/family_name"),me->name(1)));

			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѧ�������꽣����", me->name(1)));
			me->set_skill("misssword", skill + 1);
			me->FlushMySkill(me);
		}
		else
		{
			tell_object(me,"$HIYͻȻ����ɫ$HIR����$HIY��������ѣ��ԭ���㲻С�İѲ�ƪ˺�ƣ�ֻʣ��һ����Ƭ��$COM");
		}

		return 1;
	}
	
	tell_object(me,"�����Щ��ƪ��ƴ��ƴ����ʲô��ûƴ������");
	return 1;
	
}

ITEM_END;








