//yinyewang.h
//lanwood
//2000-01-09

MINGJIAOTANGZHU_BEGIN(CNmingjiao_yinyewang);

virtual void create()
{
	set_name("������", "yin liuhou");
	set("long","����һλ��ҡ���ȵ��������ӣ���һ���ײ����ۡ����ǰ�üӥ��������֮�ӡ�һ˫�۾�������磬�������䣬�������ˡ�");
	
	set("title",  "��΢������");
	set("nickname", "һ�ɳ���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "fighert");
	set("icon",young_man5);
	create_family("����",36, "����");
	set_weight(50000000);
	
	CMapping par;

	par.set("level", 4);
	set("party", par);

	set("age", 44);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 700000);
	set("score", 5000);
	
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
    set_skill("unarmed", 120);
	set_skill("hand", 200);

	set_skill("yingzhua_shou", 200);
	set_skill("literate", 120);
	set_skill("shenghuo_shengong", 120);
	set_skill("shenghuo_xinfa", 120);
	set_skill("piaoyibu", 120);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("hand", "yingzhua_shou");
	map_skill("parry", "yingzhua_shou");

	prepare_skill("hand", "yingzhua_shou");
	set("chat_chance_combat", 10);

	carry_object("baipao")->wear();
}

virtual char * chat_msg_combat()
{
	perform_action("force recover", 0);
	return 0;
}

MINGJIAOTANGZHU_END;



