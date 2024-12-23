// wudang_xiaosong.c ������

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_xiaosong);

virtual void create()
{
	set_name("������","song qingshu");
	set("long","��������Զ�ŵĶ��������ơ��������ʮ�꣬�����䵱�������г�����͵���� ");
	set("gender", "����");
	set("age", 20);
        set("icon",young_man1);

	set("attitude", "aggressive");
	
	set("repute", -100000);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 30);
	set("combat_exp", 80000);
	set("score", 10000);
	
	set_skill("force", 60);
	set_skill("taiji_shengong", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 40);
	set_skill("unarmed", 70);
	set_skill("taiji_quan", 50);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji_jian", 50);
	set_skill("liangyi_jian", 60);
	set_skill("taoism", 30);
	set_skill("literate", 40);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "liangyi_jian");
	
	create_family("�䵱��", 3, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}
/*
string ask_for_zhou()
{
    object ob;
    ob = this_player();
    command("heng");
    say(" " + ob->query("name") + "������ʲô��������ֱ�����������֣��������� ");
    command("kkkil " + ob->object_id());
    kill_ob(this_player());
    return "��ȥ���ɣ� ";
}

string ask_for_song()
{
    object ob;
    ob = this_player();
    command("xixi");
    say(" " + ob->query("name") + "�������������棬������ȥ�ɣ� ");
    message_vision("������������ؿ���$N�߽��޹���  ",ob);
    ob->move("/d/emei/qinggong");
    return "��һ����󡣬�ٺ١� ";
}

string ask_for_emei()
{
    object ob;
    ob = this_player();
    ob->set_temp("marks/�η���",1);
    say(" " + ob->query("name") + "������Ƣ�����ã����Լ����ذɣ� ");
    message_vision("�����鲻������ؿ���$N�߽��޹���  ",ob);
    ob->move("/d/emei/qinggong");
    return "��ȥ�����ˡ� ";
}
*/
NPC_END;