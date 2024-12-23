//wuying.h
//Lanwood 2000-01-09

NPC_BEGIN(CNshaolin_wuying);

void create()
{
	set_name("������ɮ",  "wuming seng");
    set("long","����������������ɮ���������Ѿ��Ƿ�����ꡣ����˫�Ȳзϡ� " );
    
    create_family("������",34, "����");
    set("attitude", "peaceful");

	set("icon",old_monk);

	set("title", "���ָ�ɮ");

	   set("age", 95);
    set("gender", "����");
    set("shen_type", 1);
    set("no_drop",1);
	
    set("con", 30);
    set("dex", 30);
    set("int", 30);
    set("str", 30);
	set("per", 15);
	set("ker", 10);

    set("max_mp", 5500);
    set("max_hp", 30000);
        
	set("mp_factor", 150);
      
	set("repute", -100000);
    set("combat_exp", 3500000);

    set_skill("buddhism",300); 
    set_skill("dodge", 300);
    set_skill("force", 300);
    set_skill("literate",300);
    set_skill("parry", 300);
    set_skill("sword", 300);
    set_skill("finger", 300);
	set_skill("wuying_jian", 300);
    set_skill("hunyuan_yiqi", 300);
    set_skill("shaolin_shenfa", 300);
    set_skill("club", 300);
    set_skill("claw", 300);
    set_skill("yizhi_chan", 300);
    set_skill("staff", 300);   
        
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "wuying_jian");
	map_skill("sword", "wuying_jian");
	                  
	set("chat_chance_combat", 15);
	set("chat_chance", 2);
	    
    carry_object("jiasha")->wear();
    carry_object("changjian")->wield();
};

char * chat_msg_combat()
{
	switch(random(2))
	{
	case 0:
			perform_action("sword wuying", 1);
			break;
	case 1:
			perform_action("force recover", 0);
			break;
	}

	return 0;
}

char * chat_msg()
{
	if(! random(2))
         return  "$CYN����ɮ���Ե����������Դ�֮������Ӱ����������˫����";
           
	return "$CYN����ɮ���Ե���������һ��ֻ���ڶ��¾Ž�֮�£���������20���մ����޵е�������Ӱ������";	
}

void attempt_apprentice(CChar * who)
{    
	char msg[255];

	if (who->query("bai_wuming") == 1 )
	{
	    say("�Ҳ���������Ϊͽ�ˣ��㻹���߰ɣ�", who);
		SendMenu(who);
        return;
	}
        
	if (DIFFERSTR(who->querystr("family/family_name"), "������") )
	{
		say(snprintf(msg, 255, "%s�뱾��������������֪�˻��Ӻ�̸��", query_respect(who)), who);
		SendMenu(who);
		return;
	}
           
	if ( who->query_skill("buddhism", 1) < 200) 
	{
		say("����֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�", who);
		say(snprintf(msg, 255, "�������ķ����棬%s�Ƿ����ò�����", query_respect(who)), who);
		SendMenu(who);
		return;
	} 
            
	if (who->query_skill("parry", 1) < 200) 
	{
		say(snprintf(msg, 255, "�ڻ��������棬%s�Ƿ����ò�����", query_respect(who)), who);
		SendMenu(who);
		return;
	}
             
	if (who->query_skill("literate",1) < 200) 
	{
		say("���¶���һ��Ե�֡�", who);
		say(snprintf(msg, 255, "%s�����Ե��������ذɡ�", query_respect(who)), who);
		SendMenu(who);
		return;
	}    
              
	if (who->query_skill("hunyuan_yiqi", 1) < 200) 
	{
		say("�����������ڼ��书���������ڹ��ķ���", who); 
		say(snprintf(msg, 255, "%s�Ƿ�Ӧ�����ڹ��϶��µ㹦��", query_respect(who)), who);
		SendMenu(who);
		return;
	}

	if (who->query_skill("force", 1) < 200) 
	{
		say(snprintf(msg, 255, "���ڹ����棬%s�Ƿ����ò�����", query_respect(who)), who);
		SendMenu(who);
		return;
	}
        
        
	if (who->query("family/generation") == 36)
	{
	    command("chat 0 �벻�������ڴ���֮�꣬���ٵ�һ������֮��\n�ã����ľͽ���������ѧ���������㣡\n");
	    command(snprintf(msg, 255, "recruit %ld", who->object_id()));

		who->set("title", "������֮�����ɮ");
		who->UpdateMe();
        
        char name[40], new_name[40];
		strncpy(name, who->querystr("name"), 40);

		name[4] = 0;
		snprintf(new_name, 40, "��%s", &name[2]);
		who->set("name", new_name); 
                
		who->set("bai_wuming", 1); 
        say(snprintf(msg, 255, "�ӽ��Ժ���ķ�������%s����ϲ������Ϊ�����ɶ��ֱ����� !", new_name), who);
		SendMenu(who);		
        return;
	}
}

NPC_END;
