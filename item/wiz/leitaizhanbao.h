// ս�� ��̨��ר��
// Lanwood 2001-07-10

ITEM_BEGIN(CIwiz_leitaizhanbao);

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

	CVector * tuned_ch = me->queryvec("channels");
	CChar * npc = find_npc(query("biwu"));
	if(! npc)
		return notify_fail("ս���Ѿ����ڡ�");
	
	AddMenuItem("�鿴��ǰ��̨���", "$0chaxun $1", me);
	AddMenuItem("�鿴��ǰ��̨�������", "$0baoming $1", me);
	
	if(tuned_ch && tuned_ch->find(npc->querystr("channel")) != tuned_ch->end() )
		AddMenuItem("�رն�սƵ��", "$0closech $1", me);
	else
		AddMenuItem("������սƵ��", "$0opench $1", me);

	SendMenu(me);
	return 1;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if( !strcmp(comm, "opench")  || !strcmp(comm, "closech")  || !strcmp(comm, "chaxun") ||!strcmp(comm, "baoming"))
	{
		CChar * npc = find_npc(query("biwu"));
		if(! npc) return notify_fail("ս���Ѿ����ڣ�");
		
		return npc->handle_action(comm, me, arg);
	}
	
	return CItem::handle_action(comm, me, arg);
}

ITEM_END;