
NPC_BEGIN(CNpub_yicai);

virtual void create()
{
	set_name("���ɿƼ�",  "echoicetech");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 49);
	set("per", 40);
	set("grant", 60);
	set("long","���ɿƼ����޹�˾����Ӫҵ���ǣ�������֪����Ϸ���й������������� ����һ�Ҽ������߻������������ۡ�������һ�������߿Ƽ���˾�� ");
	set("attitude", "friendly");

	set("file_name", querystr("base_name"));

	Load();
	set("no_huan",1);
}

int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}

int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
}

int accept_object(CChar * me, CContainer * item)
{
	char msg[255];
	
	//���ϵͳʱ��
	time_t t;	
	struct tm * newtime;
	
	time(&t);
	newtime = localtime(&t); 
	
	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(EQUALSTR(item->querystr("base_name"), "yicai_book1"))
	{
		snprintf(msg, 255, "%d��%d��/ս��ָ�ӹ�", month, day);
		if(!query(msg))
		{
			set(msg,atoi(me->id(1)));
			destruct(item);
			command(snprintf(msg, 255, "wiz 0 $HIW���ڽ����������ɿƼ�$COM��ϲ$HIR%s(%s)$COMӮ�ý��մ�,$HIR%s(%s)$COM�����Ի�������ɿƼ��ṩ��һ��$HIW��ս��ָ�ӹ١�$COM��Ϸ��\n", me->name(1),me->id(1),me->name(1),me->id(1)));
			tell_object(me,"$HIW���ڽ����������ɿƼ���ϲ��Ӯ�ý��մ󽱣��������Ի�������ɿƼ��ṩ��һ�ס�ս��ָ�ӹ١���Ϸ��$COM");
			tell_object(me,snprintf(msg, 255, "$HIW������%d��%d���������$HIRhttp://mail.gameking.com.cn/mail/ccjh/yc_huodong.htm$HIW,�Ǽ�����������ϣ��Է������Ǹ����ĳ���Ʒ��$COM",month, day+1));
			Save();
			return 1;
		}
		else
		{
			tell_object(me,snprintf(msg, 255, "$HIW�ܱ�Ǹ����$HIR%d$COM�����Ѿ���ȡ�������ڽ����������ɿƼ��ṩ�Ľ�Ʒ������������Щʱ��������$COM",query(msg)));
		}
	}
	else if(EQUALSTR(item->querystr("base_name"), "yicai_book2"))
	{
		char msg1[255];
		snprintf(msg1, 255, "%d��%d��/���ô�ս����", month, day);
		snprintf(msg, 255, "%d��%d��/���ô�ս%d", month, day,query(msg1));
		if(!query(msg) && query(msg1)<4)
		{
			set(msg,atoi(me->id(1)));
			add(msg1,1);
			destruct(item);
			Save();
			command(snprintf(msg, 255, "wiz 0 $HIW���ڽ����������ɿƼ�$COM��ϲ$HIR%s(%s)$COMӮ�ý��մ�,$HIR%s(%s)$COM�����Ի�������ɿƼ��ṩ��һ��$HIW�����ô�ս��$COM��Ϸ��\n", me->name(1),me->id(1),me->name(1),me->id(1)));
			tell_object(me,"$HIW���ڽ����������ɿƼ���ϲ��Ӯ�ý��մ󽱣��������Ի�������ɿƼ��ṩ��һ�ס����ô�ս����Ϸ��$COM");
			tell_object(me,snprintf(msg, 255, "$HIW������%d��%d���������$HIRhttp://mail.gameking.com.cn/mail/ccjh/yc_huodong.htm$HIW,�Ǽ�����������ϣ��Է������Ǹ����ĳ���Ʒ��$COM",month, day+1));
			return 1;
		}
		else
		{
			tell_object(me,"$HIW�ܱ�Ǹ���������ڽ����������ɿƼ��ṩ�Ľ�Ʒ�����ô�ս����Ʒ�Ѿ���ȡ���ˣ�����������Щʱ��������$COM");
		}
	}
	return 0;
}

NPC_END;



