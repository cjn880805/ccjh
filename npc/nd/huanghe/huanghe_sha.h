// sha.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_sha);

virtual void create()
{
	set_name("ɳ�ݵ�",  "sha tongtian");
	set("gender", "����");
	set("title", "�ƺӰ����");
	set("nickname", "��������");
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 12);
	set("icon",cateran);
	
	set("long", 
		"ɳͨ���Ǹ�ͺ�ӣ�ͷ���͹���û���ͷ����˫Ŀ������˿����\n"
		"��ͻ��������һ�����ࡣ���ӱ��꣬�书ȴ�ǳ���ظߣ�������\n"
		"���˲�����\n");
	set("combat_exp", 200000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("club", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);
	
	set("mp", 800); 
	set("max_mp", 800);
	set("mp_factor", 50);
	
	carry_object("tiejiang")->wield();
	carry_object("tiejia")->wear();
}

NPC_END;