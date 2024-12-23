// pub_susu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_susu);

virtual void create()
{
	set_name("����", "susu" );

	set("icon", young_woman2);
	set("nickname", "�Ų�Ѿ��");
	set("gender", "Ů��" );
	set("age", 14+random(3));
	set("long","���Ǹ������䲻���СѾ�ߣ������ɵ��·�Ҳ�ڲ�ס�����緢�������塣һ���������ɣ������������ݡ���������΢ʾ�⣬���ȥ�Ӳ赹ˮ��");
	set("attitude", "friendly");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 28);
	set("con", 24);
	set("dex", 20);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	set("combat_exp", 1000+random(800));
	set("score", 1000);
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 15+random(10));
	set_skill("parry", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/cdamage", 3);
	
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	return snprintf(msg,255,"����Ц������˵������λ%s��������������͸����ϲ衣",query_respect(ob) );
}

/*
void serve_tea(CChar * who)
{
	CContainer * obn;
//	CRoom * room;
	
	if( !who->query_temp("marks/sit") ) return;
	
//	if( !(room = environment()) ) return;
	
	obn = load_item("cha");//���ɲ�
//	obn->move(load_room(room));
	message_vision("�����ó�һ��С���������һ����Ũ�ı��ݴ���",who);
	
	obn = load_item("gao");//��ѩ����
//	obn->move(load_room(room));
	message_vision("�����ó�һ�����µ���ɫ���ģ��������ϣ�", who);
	
	return;
}
*/

NPC_END;