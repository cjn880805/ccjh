// liang.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_liang);

virtual void create()
{
	set_name("����ͷ", "liang ziwen");
	set("gender", "����");
	set("nickname", "�����Ϲ�");
	set("age", 43);
	set("str", 25);
	set("per", 20);
	set("dex", 16);
	set("icon",old_man1);
	
	set("long", 
		"����ͷ����еȣ���ͷ�׷�����������ɫ����������ģ���һ\n"
		"���𲼳��ۣ����ǵ����ס����ǳ���ɽ��ѧ��һ����ʦ��\n");

	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	
	set("mp", 800); 
	set("max_mp", 800);
	set("mp_factor", 50);
	
//	carry_object("changpao")->wear();
}

NPC_END;