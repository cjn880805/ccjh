//datusi.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNDaLi_datusi);

virtual void create()
{
	set_name("����˾","da tu si");

	set("age", 42);
	set("gender", "����");
	set("long", "����˾�ǰ��������ϣ��ǲ�ɽ����ϵ�ġ������ǳ��ķ�ͷ����ģ�ÿ˵һ�仰��ÿ��һ����飬���������Ʊ����Ƕ�����Ĳ���һ���������Ųʳ�ͷ�����𣬽Ų���Ь��������Ų�ͬɫ�ʵı��ǡ�ֻ����������Ȼ�ظ߾��������������˿������");
	set("attitude", "peaceful");
 	set("icon",old_man2);

	set("str", 30);
	set("per", 18);
	set("dex", 36);
	set("combat_exp", 150000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

	carry_object("lace")->wear();
};


NPC_END;
