//long.h
//code by zwb
//1-15

XIAKE_BEGIN(CNxiake_long);

virtual void create()
{
		set_name("��ľ", "long daozhu");
        set("title", "���͵�����");
        set("gender", "����" );
        set("age", 60);
        set("long","���Ǹ���������ʮ����ĺ��ӣ���üȫ�棬��ɫ������һϮ���ۣ���Ȼͦ����");
	set("icon",old_man2);	

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);

        set("hp",4000);
        set("max_hp", 12000);
        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_force", 150);
        set("combat_exp", 5000000);
        set("score", 250000);

        set_skill("force", 180);
        set_skill("taiji_shengong", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 180);
        set_skill("taiji_quan", 150);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji_jian", 160);
        set_skill("taoism", 200);
        set_skill("literate", 100);
        map_skill("force", "taiji_shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji_quan");
        map_skill("parry", "taiji_jian");
        map_skill("sword", "taiji_jian");
        set("chat_chance", 5);

        set_inquiry("������",ask_zhou);
        set_inquiry("���͵�","��������Һ�ľ�ֵ������з��ֵġ�");

 
		create_family("���͵�", 1, "����");

        carry_object("changjian")->wield();
        carry_object("cloth")->wear();
        add_money(1000);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "��ľ΢΢Ц������Ҳ��Ϊ�����������ࣿ";
	case 1:
		return "��ľ΢΢Ц����̫������ʲô��";
	}
	return "";
}

XIAKE_END;