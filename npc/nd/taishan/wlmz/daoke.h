//taishan_daoke.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_daoke);

virtual void create()
{
	set_name("����","dao ke");
	set("gender", "����");
	set("age", 20);
	set("long", "��һ��������⣬һ�������ɷ��ģ��������������η��");
	set("combat_exp", 15000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 45);
	set_skill("blade", 45);
	set_skill("parry", 40);
	set_skill("dodge", 40);

        carry_object("gangdao")->wield();
        carry_object("cloth")->wear();

	add_money(1000);
}

void init()
{
	object room, ob;
	string mengzhu;
	
	if(!( room = find_object("/d/taishan/fengchan")) )
	room = load_object("/d/taishan/fengchan");

	if( objectp(ob = present("mengzhu", room)) ) 
	mengzhu = ob->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "������$N����Ϊ��˵�������������˼Һã�\n" NOR, 
		this_player());
	}	
}

NPC_END;