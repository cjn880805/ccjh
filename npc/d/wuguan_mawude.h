// wuguan_mawude.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwuguan_mawude);

virtual void create()
{
	set_name("�˷ɺ�", "lao pan");
	set("title","��ţ��ݹݳ�");
	set("long", "����ү������ݵĵ����ߣ�����һ�����ˣ���������Я�������ϵ���׳�� ");
	set("gender", "����");
	set("age", 95);
        set("icon",old_man2);

	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("hand", 80);
	set_skill("blade", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("combat_exp", 400000);
	set("shen_type", 1);
   set_inquiry("�ֻ�", "�ֻ��ó�ֵ��̫�������ˣ�");
}

virtual int recognize_apprentice(CChar * ob)
{
	if (ob->query_temp("marks/jinniu_paied")!=1) return 0;
	return 1;
}

NPC_END;