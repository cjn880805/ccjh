// mingjiao_litianyuan.c

//code by Fisho
//date:2000-12-21


MINGJIAOTANGZHU_BEGIN(CNmingjiao_litianyuan);

virtual void create()
{
    set_name("�����",  "li tianbi");
	set("long","����һλ�������ܴ�������ߣ���һ���ײ����ۡ���һ˫�۾�����Ц���еģ�����֪Ϊʲô��������������η����Ы��");
	
	set("title",  "����������" );
	set("nickname", "��ü��Ŀ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",old_man1);
	create_family("����",36, "����");
	set_weight(50000000);
	
	CMapping par;

	par.set("level", 4);
	set("party", par);

	set("age", 55);
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
    set_skill("unarmed", 200);

	set_skill("houquan", 200);
	set_skill("literate", 120);
	set_skill("shenghuo_shengong", 120);
	set_skill("shenghuo_xinfa", 120);
	set_skill("piaoyibu", 120);
	
    map_skill("force", "shenghuo_shengong");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "houquan");
	map_skill("unarmed", "houquan");
	prepare_skill("unarmed","houquan");

	set("chat_chance_combat", 10);

    carry_object("baipao")->wear();
}

virtual char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("unarmed zhen", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

MINGJIAOTANGZHU_END;



