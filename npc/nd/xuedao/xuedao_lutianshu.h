// lutianshu.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_lutianshu);

virtual void create()
{
       set_name("½���", "Lu tianshu");
       set("long", 
		"�����������桰�仨��ˮ���е��ϴ�\n"
		"��������н��ϣ��������壬����������ƣ�����������\n");
       set("gender", "����");
       set("nickname", "����½��");
       set("age", 51);
       set("attitude", "peaceful");
       set("shen_type", 0l);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);
	set("icon",young_man5);

       set("hp", 2000);
       set("max_hp", 2000);
       set("mp", 2000);
       set("max_mp", 2000);
       set("mp_factor", 30);
       set("combat_exp", 800000);
       set("shen_type", 1);

       set_skill("force", 100);
       set_skill("hunyuan_yiqi", 100);
       set_skill("dodge", 100);
       set_skill("shaolin_shenfa", 100);
       set_skill("unarmed", 100);
       set_skill("jingang_quan", 100);
       set_skill("parry", 100);
       set_skill("blade", 100);
       set_skill("wuhuduanmendao", 100);
       set_skill("literate", 20);

       map_skill("force", "hunyuan_yiqi");
       map_skill("dodge", "shaolin_shenfa");
       map_skill("unarmed", "jingang_quan");
       map_skill("parry", "wuhuduanmendao");
       map_skill("blade", "wuhuduanmendao");
	set("chat_chance", 20);


       carry_object("gangdao")->wield();
}

virtual char * chat_msg()
{
	return "½��Ƽ���������Х����磺���仨��ˮ�������������ƾ�����ԶԶ������";
}

NPC_END;