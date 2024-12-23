// shaolin_xiaolu.c

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_xiaolu);

virtual void create()
{
	set_name("½����", "lu guanying");
	set("title", "����ׯ��ׯ��");
	set("long", "���ǹ���ׯ��ׯ��½���ۡ������������������׳�������ж�֮�����Ķ��ţ�ǫ������һ�������ӵܷ緶������������̫��Ⱥ�������죬��֪�����Ǽ١�");
	set("gender", "����");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
        set("icon",young_man1);
	
	set("max_hp", 1800);
	set("hp", 600);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	set("combat_exp", 150000);
	set("score", 6000);
	
	set_skill("force", 50);
	set_skill("hunyuan_yiqi", 50);
	set_skill("dodge", 80);
	set_skill("shaolin_shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo_zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei_dao", 50);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "banruo_zhang");
	map_skill("parry", "cibei_dao");
	map_skill("blade", "cibei_dao");
	
	set_inquiry("����ׯ", ask_me);
	
	set("book_count", 1);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}
/*
init()
{
add_action("do_decide", "decide");
}
*/
static char * ask_me(CNpc *who,CChar *me)
{
	static char msg[255];
	me->set_temp("guiyun/decide",1);
	return snprintf(msg,255,"����ׯ�������¾Ӵ������%s���⣬ �ҿ�����һ���Ϊ������",query_respect(me) );
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"decide") == 0)
		return do_decide(me);
	return 0;
}

int do_decide(CChar *me)
{
	CContainer *ob;
	char msg[255];
	if (!me->query_temp("guiyun/decide"))
	{
		message_vision("$N��$n��ֵ�˵������Ҫ�������", me, this);
		return 1;
	}
	me->delete_temp("guiyun/decide");
	ob = load_item("xin");
	ob->move(me);
	message_vision("$N˫�ֱ�ȭ������������ׯ�������ˡ�", me);
	message_vision("$N˵�����ã�", this);
	message_vision("$N��$nһ�����š�", me, this);
	message_vision(snprintf(msg,255,"��λ%s���ȵ���ׯ�̺����գ��Ժ���ͼ����", query_respect(me)  ),me);
	return 1;
}
NPC_END;