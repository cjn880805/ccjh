// wuzhirong.h   ��֮��
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity2_wuzhirong);

virtual void create()
{
	set_name("����֮", "wuzhirong");
	set("gender", "����");
	set("age", 40);
	set("long", "ԭ�鰲��֪��,��̰������,�ձ��淢��ְ�������ü������,һ����֪���Ǻ��ˡ�\n");
	set("attitude", "peaceful");
	set("icon", young_man3);
	set("shen_type", -1);
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 150);
	set("hp", 1000);
	set("max_hp", 1000);
	set("mp", 500);
	set("max_mp", 500);
	set("combat_exp", 5000);
	set("score", 5000);
    set_skill("literate", 100);
	
	carry_object("cloth")->wear();
//	carry_object("goldleaf");
}

NPC_END;