//heimuya_zhang1.h �ų˷�
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_zhang1);

virtual void create()
{
	set_name("��ʣ��", "zhang chengfeng");
	set("nickname", "�����ħ");
	set("title", "������̳���");
	set("gender", "����");
	set("age", 42);
	set("shen_type", -1);
	set("long", "����������̳��ϡ�");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man5);

	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 300);

	set("combat_exp", 1500000);
	set("shen_type", -1);
    
	set("chat_chance", 5);

	set_inquiry("��ľ��", "���̵��ӻ�ֽ������Ʒ������£�");
	set_inquiry("�������", "���̵��ӻ�ֽ������Ʒ������£�");
	set_inquiry("��ľ��", "���Ǳ��̽������ƣ���������������٣�");
//	set_inquiry("����" :   (: shang_ya :),);

	set_skill("force", 150);
	set_skill("kuihua_xinfa", 150);
	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("dodge", 150);
	set_skill("lingxu_bu", 150);
	set_skill("parry", 150);
	set_skill("club", 150);
	set_skill("weituo_gun", 150);

	map_skill("force", "kuihua_xinfa");
	map_skill("club", "weituo_gun");
	map_skill("parry", "weituo_gun");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu_bu");

	create_family("�������", 2, "����");

	carry_object("shutonggun")->wield();
	carry_object("cloth")->wear();
}

/*
int shang_ya()
{
    object ob, myenv ;
    ob = this_player ( ) ;
    if (ob->query("family/family_name") == "�������")
    {
        message_vision("�ų˷�һ���֣���������һ���������\n",ob);
        message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", ob);
        myenv = environment (ob) ;
        ob->move ("/d/heimuya/basket");
	call_out("goto_heimuya", 10, ob) ;
       	return 1;
    }
    else  
    message_vision("�ų˷��������´�����$Nһ�£�ʲô�����£���ĺ�ľ���أ���\n",ob);
    return 1;
}

int accept_object(object who, object ob)
{
    object myenv ;
    if (ob->query("id") == "heimu ling")
    {
        message_vision("�ų˷��$N˵���ã���λ" + RANK_D->query_respect(who) + "�����Ǿ���ɣ�\n" , who);
        message_vision("�ų˷�һ���֣���������һ���������\n", who);
        message_vision("$Nһ�������˵��������������ؽ�����ȥ......\n", who);
        myenv = environment (who) ;
        who->move ("/d/heimuya/basket");
	call_out("goto_heimuya",10,who) ;
       	return 1;
    }
    else  
    {
	message_vision("�ų˷��$N˵�����ˣ�ң���\n", who);
        this_object()->kill_ob(who);
    }
    return 0;
}

void goto_heimuya (object ob)
{
    tell_object(ob , "����ǰһ����һ������ɫ����������ǰ�����ǻԻ͡�\n");
    ob->move ("/d/heimuya/chengdedian") ;
}
*/
NPC_END;