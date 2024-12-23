//pub_baoguanyuan.h������Ա
// dieer 2002 9.9

NPC_BEGIN(CNpub_baoguanyuan);

virtual void create()
{
	set_name("����Ա","baoguanyuan");
	
	set("gender", "����");
	set("age", 40);
	set("long","����ת����Ʒ����Ա����ӱ�ķ�����ת�ƹ�������Ʒ����������ء���");
	set("attitude", "friendly");
	set("icon", 17);
	
	set("per", 22);
	set("str", 11);
	set("int", 30);
	set("con", 15);
	set("dex", 11);
	
	set("max_hp", 10000000);
	set("hp", 9000000);
	set("max_mp", 1000);
		
	set_skill("force", 50);
	set_skill("unarmed",50);

	set_inquiry("��ȡ��Ʒ", ask_wuping );
}
	
static char * ask_wuping(CNpc * me, CChar * who)
{
	char msg[255];
	
	int longret = who->query("item/count");
	
	if(!longret)
	{
		me->say("��û��ת��ʲô��Ʒ�������Ѿ������ˡ�", who);
		who->del("item");
	}
	else
	{
		snprintf(msg,255, "�㹲ת����%d����Ʒ���һ�һ�ν�����һ����Ʒ��Ҫ�ǵ���ʱ�鿴�Լ��ĸ��أ����Ѿ��ò����˻�����Ҫ������",who->query("item/count"));
		me->say(msg, who);
		snprintf(msg,255,"item/item%d",who->query("item/count"));
		CContainer * bot=load_item(who->querystr(msg));
		who->add("item/count",-1);
		snprintf(msg,255, "�������%s������ʣ%d����Ʒû����ȡ��",bot->querystr("name"),who->query("item/count"));
		me->say(msg,who);
		who->del(msg);
		bot->move(who);
	}
	me->SendMenu(who);
	return 0;
}
	
NPC_END;
