// wudang_zhao.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNwudang_zhao);

virtual void create()
{
	set_name("�԰봨", "zhao banshan" );
	set("title", "�컨��������");
	set("nickname",  "ǧ������"  );
	set("gender", "����");
	set("age", 48);
        set("icon",old_man1);

	set("long",  "��һ�����ֵ�����Ц��������һ���ܴ���ĸо�����ԭ������̫�������Ŵ���ӡ������������� ����һ�ְ��������̫����������ƥ�С���������� ��ɢ֮��Ͷ��컨�ᡣ�ܵñ��컨���ϵ�����ǧ����ʶ��");
 	set("attitude", "peaceful");
	set("class", "fighter");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	
	set("hp", 2500);
	set("max_hp", 7500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("combat_exp", 800000);
	
	set_skill("force", 150);
	set_skill("taiji_shengong", 150);
	set_skill("unarmed", 150);
	set_skill("taiji_quan", 150);
	set_skill("throwing", 200);
	set_skill("hanxing_bada", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("mantian_xing", 200);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("taiji_jian", 150);
	
	map_skill("force"  , "taiji_shengong");
	map_skill("unarmed", "taiji_quan");
	map_skill("dodge"  , "tiyunzong");
	map_skill("parry"  , "taiji_jian");
	map_skill("sword"  , "taiji_jian");
	map_skill("throwing"  , "hanxing_bada");
	set("chat_chance_combat", 30);  
	
	carry_object("changjian")->wield();
	carry_object("jili")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg_combat()
{
	char msg[80];
	CContainer * changjian = PresentName("changjian", IS_ITEM);
	CContainer * jili = PresentName("jili", IS_ITEM);
	CContainer * weapon = query_weapon();

	switch(random(5))
	{
	case 0:
		if(changjian && !weapon)
			command(snprintf(msg, 80, "wield %ld", changjian->object_id()));
				
		break;
	case 1:
		if(jili && ! weapon)
			command(snprintf(msg, 80, "wield %ld", jili->object_id()));
				
		break;
	case 2:
		g_Channel.do_emote(this, 0, "haha", 0);
		break;
	
	case 3:
		if(weapon == changjian)
			command(snprintf(msg, 80, "unwield %ld", changjian->object_id()));
		break;
	case 4:
		if(weapon == jili)
			command(snprintf(msg, 80, "unwield %ld", jili->object_id()));
		break;
	}
	return "";
}

NPC_END;