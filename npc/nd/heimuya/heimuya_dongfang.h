//dongfang.h
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNHeiMUYa_dongfang);

virtual void create()
{
	
	set_name("��������","dong fang");
	
    set("nickname",  "�����޵�" );
    set("title", "������̽���");
    set("gender", "����");
    set("shen_type", -1);
    set("age", 42);
    set("long","������������̽������ų����˿ɵУ������֪��Ϊʲô����Ϊ��������������");
    set("attitude", "peaceful");
	set("icon",old_man2);
	
    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
	
    set("chat_chance", 1);
	
    set_inquiry("����","���ֱ���Ұ��˵�����,������ѽ�� ");
    set_inquiry("��������","������ܰ���ȡ�ÿ������䣬��һ������л�㡣");
	
    set("hp", 4000);
    set("max_hp", 12000);
    set("mp", 4500);
    set("max_mp", 4500);
    set("mp_factor", 400);
	
    set("combat_exp", 2500000);
    
	
    set_skill("force", 250);             // �����ڹ�
    set_skill("finger", 250);            // ����ָ��
    set_skill("unarmed", 280);           // ����ȭ��
    set_skill("dodge", 250);             // ��������
    set_skill("parry", 250);             // �����м�
    set_skill("sword", 350);             // ��������
    set_skill("pixie_jian", 350);        // ��а����
    set_skill("changquan", 280);         // ̫�泤ȭ
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua_xinfa", 250);      // �����ķ�
	
    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	
    create_family("�������", 2, "����");
	
    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();
	if (random(3)==0)
		carry_object("heiyugao");
	set("no_huan",1);
}


virtual void attempt_apprentice(CChar * player)
{
	
    if (player->query_int() < 30) 
	{
        say ("�Ҳ������ʲ�ĵ��ӣ�����ذɣ�",player);
    }else if (DIFFERSTR(player->querystr("gender"), "����") )
	{
        say(" Ҫ���񹦣������Թ���",player);
    }else if (player->query("repute") >100000 || player->query ("repute") < -100000 )
	{
        say("�Һ�ľ�������������������������ֳ�������򽻵�������ذɣ�", player);
    }
	else
	{
		say("�ܺã��ܺá�", player);
		SendMenu(player);
		recruit_apprentice(player);
		return;
	}
	
	SendMenu(player);
	
	
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if (me->query_temp("tmark/��") == 1 )
        message_vision("�����������˿�$N��˵��������������˭Ҳ��Ƿ˭,�㲻Ҫ������ѧϰ�����ˡ�", me);
	
    me->add_temp("tmark/��", -1);
	return 0;
}

virtual int recognize_apprentice(CChar * me)
{
	if(EQUALSTR(me->querystr("party/party_name"), "��ľ��") ) return 1;
    
    if (! me->query_temp("tmark/��"))
        return 0;
	
    return 1;
}

virtual int accept_object(CChar * player , CContainer * item)
{
	
	if ( EQUALSTR(item->querystr("base_name"), "kuihua") )	//û��kuihua baodian1����������Ϊkuihua��Modify by Lanwood 2000-12-27
	{
		if (!player->query_temp("tmark/��")) 
			player->set_temp("tmark/��",100);
		
		message_vision("�����������˿�$N�������ؼ������˵�ͷ��˵�����ѵ��㽫�����ͻء������ҵĶ����Ҿ������ˡ���Ϊ����,����Դ�������ѧ�㹦��", player);
		player->add_temp("tmark/��", 100);
		
		return 1;
	}
	
	return 0;
}
NPC_END;