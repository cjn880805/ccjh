// wei_su.h ����
// �ز�	2002��12��25

NPC_BEGIN(CNwei_su);

virtual void create()
{
	set_name("����","su quan");
	set("title",  "����������" );
	set("long", "�����ǵ�����������С�����ˡ�");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	set("icon",young_man2);	
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1000000);
	set("score", 400000);

    set_skill("force", 180);
    set_skill("dodge", 180);
    set_skill("unarmed", 180);
    set_skill("strike", 150);
    set_skill("parry", 180);
    set_skill("staff", 150);
    set_skill("sword", 150);
	set_skill("literate", 120);
	
	set_skill("shenlong_xinfa", 160);
	set_skill("yixingbu", 160);
	set_skill("shenlong_bashi", 160);
	set_skill("huagu_mianzhang", 160);
	set_skill("shedao_qigong", 160);

	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	carry_object("cloth")->wear();
	carry_object("duanjian")->wear();
	add_money(10000);

	call_out(do_die, 900);
	set("no_kill",1);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	destruct(npc);
}

NPC_END;