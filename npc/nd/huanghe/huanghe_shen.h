// shen.c
//sound 2001-07-16

NPC_BEGIN(CNhuanghe_shen);

virtual void create()
{
	set_name("�����", "shen qinggang");
	set("gender", "����");
	set("title", "�ƺ��Ĺ��ϴ�");
	set("nickname", "�ϻ굶");
	set("age", 32);
	set("str", 25);
	set("dex", 16);
	set("per", 16);
	set("icon",cateran);
	
	set("long", "������ǻƺ��Ĺ���ϴ��ǹ�������ɳ�ݵ�ͨ��Ĵ���ӣ���ʹ������");
	set("combat_exp", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 30);
	set_skill("force", 30);
	set_skill("blade", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;