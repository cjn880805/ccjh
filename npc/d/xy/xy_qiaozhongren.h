//xy_qiaozhongren.h	������
//�ز� 2003��4��3

NPC_BEGIN(CNxy_qiaozhongren);

void create()
{
	set_name("������","qiao zhong ren");
	set("gender", "����");
	set("age", 27);

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);

};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("xy/renwu7_1") && !me->query("xy/renwu8") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ�ʹ��ھ���7������","jingtong",me);
		}
		else if(!strcmp(ask, "jingtong") )
		{
			say("������¶�����ӵ���ɫ������7Ҳ�ܰ�����ס��7���͵���1+1+1+1+1+1+1���",me);
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




