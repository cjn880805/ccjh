//xinran.h
//Lanwood
//2001-01-09

MINGJIAOZHANGQISHI_BEGIN(CNmingjiao_xinran);

virtual void create()
{
	set_name("��ȼ", "xin ran");
	set("long","����һλ�ߴ��ΰ���������ӣ���һ���ײ����ۡ����������������е���ͷ����������򲻵�֮�£������������ݡ�");
	
	set("title",  "�һ�������ʹ");
	set("level",7);
	
	set("gender", "����");
	set("attitude", "friendly");
	set("icon",young_man1);
	create_family("����",37, "����ʹ");
	set_weight(50000000);
	
	CMapping par;

	par.set("level", 3);
	set("party", par);

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 200000);
	set("score", 5000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
    set_skill("unarmed", 80);
	set_skill("blade", 120);
	set_skill("fenglei_dao", 120);
	set_skill("literate", 80);
	set_skill("shenghuo_shengong", 80);
	set_skill("shenghuo_xinfa", 80);
	set_skill("piaoyibu", 80);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "fenglei_dao");
	map_skill("blade", "fenglei_dao");
	
	carry_object("baipao")->wear();
	carry_object("jiedao")->wield();
}

MINGJIAOZHANGQISHI_END;



