//wiz_newgift.h
//code by zwb
//12-25

NPC_BEGIN(CNwiz_newgift);


virtual void create()
{
	
	set_name("ɢ��ͯ��","liwu shizhe");

	set("icon", young_woman1);
	set("title", "����ʹ��");
	set("gender", "����" );
	set("age", 43);
	set("per", 3);
	set("long","���������û������ʹ��");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("grant", 99);
	set_inquiry("������������","����һ�����콣,�ҾͰ�������е������û��ͳ����");
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("msg","���س�������ȫ����ʦ��ף�����Ϸ���ģ�");
	set("����","zhuguo");
	set("no_huan",1);
//	carry_object("cloth")->wear();
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "ytjian") )
	{
		destruct(ob);
		//g_Channel.do_channel(&g_Channel, 0, "wiz", "$HIR��������������ˣ�ȫ����ʦ������������ˣ�");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR��������������ˣ�ȫ����ʦ������������ˣ�");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIRף������µ�һ������彡���������³ɡ������д��ˡ�");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIRף����ڽ����У�money��࣬�����࣬���Ѷ�࣬ÿ��һ�������顣");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR��ϲ���ƣ���������������зݣ�������࣡");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR�ЩةЩ������񩤩Щ����������੤����������ȡ� ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR�ةЩة��С������੤�����򡡩��������𩸩Щ��� ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR���੤�����������������������ة��ء������੤��  ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR�񩦡𩦩����ة��੤�������𡡡��񡡣����� ��  ");
		g_player();
		g_lost();
		return 1;
	}
	return 0;
}
*/

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "ytjian") )
	{
		char msg[255];
		destruct(ob);
		snprintf(msg, 255, "wiz 0 $HIR%s",querystr("msg"));
		command(msg);
//		g_Channel.do_channel(who, NULL, "wiz", snprintf(msg, 255, "$HIR%s",querystr("msg")));
		g_player();
		g_lost();
		return 1;
	}
	return 0;
}

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if(query("����С��") && obj->query("age")>=query("����"))
			continue;
		if(query("�������") && obj->query("age")<=query("����"))
			continue;
		if(querystr("�Ա�")[0]&& DIFFERSTR(obj->querystr("gender"), querystr("�Ա�")))
			continue;
		if(query("�ȼ�С��")&& obj->query("level")>=query("�ȼ�"))
			continue;
		if(query("�ȼ�����")&& obj->query("level")<=query("�ȼ�"))
			continue;
		if(query("����С��")&& obj->query("combat_exp")>=query("����"))
			continue;
		if(query("�������")&& obj->query("combat_exp")<=query("����"))
			continue;
        tell_object(obj,"����Ʈ��������һ���������ƫ����������Ļ��С���");

		load_item(querystr("����"))->move(obj);

//		load_item("hongbao")->move(obj);
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;




