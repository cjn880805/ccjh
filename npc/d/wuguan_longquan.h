// wuguan_longquan.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwuguan_longquan);

virtual void create()
{
	set_name("����", "long quan");
	set("title","��ţ��ݽ�ϰ");
	set("long", "����һ��Ӣ�������������ε���ݽ�ϰ��һ���Ů����ʮ��ϲ������Ϊʦ�� ");
	set("gender", "����");
	set("age", 21);
        set("icon",young_man1);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("claw", 80);
	set_skill("blade", 80);
	set_skill("axe", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
        set_inquiry("����", "�����Թſ���ޣ��˺������޾��ڣ�");
}
virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

virtual char *chat_msg()
{
	return "������̾һ���������Թſ���ޣ��˺������޾��ڣ�";
}

NPC_END;