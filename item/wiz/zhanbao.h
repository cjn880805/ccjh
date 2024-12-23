// ս�� ������ר��
// Lanwood 2001-07-10

ITEM_BEGIN(CIwiz_zhanbao);

void create(int nFlag = 0)
{
    set_name("��ʱս��", "zhan bao");
    set_weight(100);
    
	set("long", "����ʱ��������ս����");        
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{		
	AddMenuItem("�鿴��ս����", "$0lo $1", me);

	CVector * tuned_ch = me->queryvec("channels");
	CChar * npc = find_npc(query("biwu"));
	if(! npc)
		return notify_fail("ս���Ѿ����ڡ�");
	
	if(tuned_ch && tuned_ch->find(npc->querystr("channel")) != tuned_ch->end() )
		AddMenuItem("�رն�սƵ��", "$0closech $1", me);
	else
		AddMenuItem("������սƵ��", "$0opench $1", me);

	SendMenu(me);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "lo") == 0)
	{
		char msg[255], cmd[20];

		CChar * npc = find_npc(query("biwu"));
		if(! npc) return notify_fail("ս���Ѿ����ڣ�");

		int state = npc->query("state");

		for(int i=0; i<=state; i++)
		{
			AddMenuItem(snprintf(msg, 255, "�鿴��%ld�ֶ�������", i), 
				snprintf(cmd, 20, "$0lookup $1 %ld", i), me);	
		}

		SendMenu(me);
		return 1;	
	}
	else if(strcmp(comm, "lookup") == 0 || strcmp(comm, "biwu") == 0
		|| strcmp(comm, "summon") == 0 || strcmp(comm, "opench") == 0
		|| strcmp(comm, "closech") == 0 || strcmp(comm, "goto") == 0)
	{
		CChar * npc = find_npc(query("biwu"));
		if(! npc) return notify_fail("ս���Ѿ����ڣ�");

		return npc->handle_action(comm, me, arg);
	}


	return CItem::handle_action(comm, me, arg);
}

ITEM_END;