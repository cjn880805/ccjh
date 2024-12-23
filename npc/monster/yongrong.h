//yongrong.h
//code by Lanwood
//2001-2-20

char rnd_say[][80] = {
	"�Һ�Ȼ����ȥ����.",
	"Ϊʲô��Ҷ�������?��",
	"�ɲ����Ը�����������ɱ�ˣ�",
	"���������鲻���, ��ҿ�ҪС����.",
	"��������������?",
	"˭�뽲�����£�",
	"���ڼ����ˣ�",
	"Ϊʲô��˵����?",
	"Ϊʲô����ȥ˯����?",
	"˭��ȥ����Ӱ?",
	"�ҿ��Գ�ȥɱ����?",
    "С���ֱ����һ����å! ",
	"�Ҷ�MUD����ûʲô�ø�.",
	"�Ҷ��������ûʲô��Ȥ.",
	"�Һ���ܱ�Ү.",
	"�������������?",
};

NPC_BEGIN(CNmonster_yongrong);

virtual void create()
{
	set_name("Ӻ��", "yongrong");
	set("nickname", "����֮��");
	set("long",  "�����ü�������������˫�۾����ĵ�ֱ���Թ��˻��ǡ�����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��������ȻһЦ�����������·����۲���ת֮�䣬���һ����������飬�������м����ľ��硣");
	set("title", "��ն��");
	set("gender", "Ů��");
	set("age", 21);
	set("rank_info/respect", "С����");
	set("max_hp", 30000);	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 100);
	set("inmortal",1);
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("no_get_from", 1);
	set("killed", "С��");
	set("killer", "Ӻ��");

	set_skill("force", 200);
	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);
	set_skill("blade", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);

	set_skill("yunlong_jian", 150);
	set_skill("yunlong_xinfa", 200);
	set_skill("yunlong_shengong", 200);
	set_skill("yunlong_shenfa", 200);
	set_skill("shenxing_baibian", 200);
	set_skill("yunlong_bian", 150);
	set_skill("yunlong_shou", 200);
	set_skill("yunlong_zhua", 200);

	map_skill("dodge", "shenxing_baibian");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_shou");
	map_skill("claw", "yunlong_zhua");
	map_skill("sword", "yunlong_jian");
	map_skill("whip", "yunlong_bian");
	
	prepare_skill("hand", "yunlong_shou");
	prepare_skill("claw", "yunlong_zhua");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set("env/wimpy", 90);
//	set_inquiry("С��", ask_bf);
		
	set("chat_chance", 3);
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 5000000);
	set("chat_chance_combat", 20);  
	
	carry_object("ring")->wear();
	//carry_object("crystal")->wear();
	carry_object("shouzhuo")->wear();
	carry_object("majia")->wear();
	carry_object("baojia")->wear();
	carry_object("bishou")->wield();
	carry_object("yupei")->wear();
	carry_object("heilongbian")->wield();
	carry_object("mugun")->wield();
	g_Channel.register_relay_channel("chat", this);
}

virtual char * chat_msg()
{
	switch(random(19))
	{
	case 0:
		return "Ӻ�ݺ�Ȼ���˸�������Ц��: �������ȥ������";
	case 1:
		command("sing2");
		break;
	case 2:
		command("angry");
		break;
	case 3:
		command("slogan2");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("laughproud");
		break;
	case 7:
		return "Ӻ�ݺ�Ȼ����˵���򵹳���̶����С�䣡";
	case 8:
		return "Ӻ�����ĵ������־̾��: ����һ���ˣ���û��˼��";
	case 9:
		return "Ӻ�����������һ���С�֣������°�˵: ˭�����˵˵��?";
	case 10:
		return "Ӻ��ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������";
	case 11:
		return "Ӻ�ݺ�Ȼݸ��һЦ��: С��������Ҫ��ɱ˭�أ�";
	case 12:
		return "Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�";
	case 13:
	case 14:
//		drool();
		break;
	case 15:
	case 16:
	case 17:
	case 18:
		command("reclaim");
		break;
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	char msg[255];
	CChar * me = NULL;

	if(environment()->Query(IS_FIGHTROOM))
	{
		me = ((CFightRoom *)environment())->Select_Member(1 - query_team());
	}

	if(! me) return 0;

	switch(random(27))
	{
	case 0:
		return "Ӻ������̾���������������Ǻο���?";
	case 1:
		command("!!!");
		break;
	case 2:
		command("smile");
		break;
	case 3:
		command("poem");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("giggle");
		break;
	case 7:
		command("waggle");
		break;
	case 8:
		command("laughproud");
		break;
	case 9:
		command("nomatch");
		break;
	case 10:
		command("xixi");
		break;
	case 11:
		command("chat 0 ���кλ����������? ����ͳ�ȫ����ɡ�");
		break;
	case 12:
		command(snprintf(msg, 255, "chat 0 ����%s�������ִ�Բ���?", query_rude(me)));
		break;
	case 13:
	case 14:
	case 15:
	case 16:
		unwield_weapon("bishou");
		break;
	case 17:
	case 18:
	case 19:
	case 20:
		wield_weapon("bishou");
		break;
	case 21:
	case 22:
	case 23:
		wield_weapon("bian");
		break;
	case 24:
	case 25:
	case 26:
		unwield_weapon("bian");
		break;
	}

	return 0;
}

int add_phrase(const char * who, const char * arg)
{
	char msg[512];

	memcpy(msg, arg, 512);

	replace_string(msg, "?", "", 512);
	replace_string(msg, "��", "", 512);
	replace_string(msg, "��", "", 512);
	replace_string(msg, "!", "", 512);
	replace_string(msg, "��", "", 512);
	replace_string(msg, "��", "", 512);
	replace_string(msg, "��", "", 512);
	replace_string(msg, "Ү", "", 512);
	replace_string(msg, "��", "", 512);

	if(msg[0]) 
	{
		char key[60];

		snprintf(key, 60, "memory/%s", who);

		CVector v;

		v.append(msg);
		_M.add(key, v);
		return 1;
	}
	
	return 0;
}

virtual void relay_channel(CChar *  ob, const char * channel, const char * msg)
{
	const char * who;

	if( !userp(ob) || (DIFFERSTR(channel, "chat")) ) return;
	who = ob->querystr("name");

	if(ob == this) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->querystr("name"));
}

virtual void relay_say(CChar * ob, char * msg)
{
	const char * who;

	if( !userp(ob) ) return;
	who = ob->querystr("name");

	if( ob==this ) return;

	if( add_phrase(who, msg) &&	random(10) > 3 )
		drool(msg, ob->querystr("name"));
}

virtual void relay_emote(CChar * ob, string verb)
{
	char msg[255];

    if( !userp(ob) ) return;
	
	if( verb == "hug" || verb == "kiss" || verb == "mo" || verb ==  "18mo" || verb == "nocloth" )
	{
		if ( EQUALSTR(ob -> querystr("gender"), "����") || EQUALSTR(ob -> querystr("gender"), "����" ))
		{
			command(snprintf(msg, 255, "chat 0 С���������%s��Ҫ�����ң�", ob->name(1)));
			command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ҳ��һ����ɫ֮ͽ ��", query_rude(ob)));
		}
		else
		{
			message_vision("Ӻ�ݶ�$NЦ����������ͬΪŮ��������ôϲ��Ҳ��Ҫ����������", ob);
			command("giggle");
			command(snprintf(msg, 255, "chat 0 �벻��%s��%s����Ȼ��һ����̬��", ob->name(1), query_rude(ob)));
		}
		
		message_vision("$Nҡ��ҡͷ����$n����̾���������������Ǻο���?", this, ob);
		if(wizardp(ob))		
		{
			ob->set("immortal",0l);
			command(snprintf(msg, 255, "aim %ld", ob->object_id()));
			command("shoot");
		}
		
		kill_ob(ob);
	}
    else
	{
       if( random(10) < 8 )
       {
			command(snprintf(msg, 255, "%s %ld", verb.c_str(), ob->object_id()));
 			return;
       }
       else
		{
			if( verb == "kick" || verb == "taste" || verb == "hate" || verb == "brag"
				|| verb == "showscar" || verb == "callname" || verb == "slap" 
				|| verb == "rascal" || verb == "slapsb" || verb == "bite"
				|| verb == "knife" || verb == "die" || verb == "drug" 
				|| verb == "cook" || verb == "stuff" || verb == "shit"
				|| verb ==  "shutup" || verb == "stare" || verb == "praisemapi"
				|| verb == "anniversary")
			{
				switch(random(50))
				{
				case 0: 
					command(snprintf(msg, 255, "kick %ld", ob->object_id()));
					command("xixi");
					break;
				case 1:
					command(snprintf(msg, 255, "slap %ld", ob->object_id()));
					command("xixi");
					break;
				case 2:
					command(snprintf(msg, 255, "drug %ld", ob->object_id()));
					break;
				case 3:
					command("smell");
					command(snprintf(msg, 255, "cook %ld", ob->object_id()));
					break;
				case 4:
					command(snprintf(msg, 255, "trip %ld", ob->object_id()));
					break;
				case 5:
					command(snprintf(msg, 255, "knife %ld", ob->object_id()));
					command(snprintf(msg, 255, "doubt %ld", ob->object_id()));
					break;
				case 6: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 ����%s��%s���滵��", ob->name(1), query_rude(ob)));
					break;
				case 7: 
					command("shutup ");
					command(snprintf(msg, 255, "shutup %ld", ob->object_id()));
					break;
				case 8: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 С���������%s��Ҫ�����ң�", ob->name(1))) ;
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 9:
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 10: 
					command(snprintf(msg, 255, "shit %ld", ob->object_id()));
					break;
				case 11: 
					command("hero");
					command(snprintf(msg, 255, "shout %ld", ob->object_id()));
					break;
				case 12: 
					command("shake");
					command(snprintf(msg, 255, "nomatch %ld", ob->object_id()));
					break;
				case 13: 
					command(snprintf(msg, 255, "stare %ld", ob->object_id()));
					command(snprintf(msg, 255, "hit %ld", ob->object_id()));
					break;
				case 14: 
					command("sneer");
					break;
				case 15: 
					command(snprintf(msg, 255, "chat ��Ӵ��%s���%s�治Ҫ����", ob->name(1), query_rude(ob)));
					command("faint");
					break;
				case 16: 
					command("shrug");
					break;
				case 17: 
					command(snprintf(msg, 255, "poke %ld", ob->object_id()));
					command("hehe");
					break;
				case 18: 
					command("blush");
					break;
				case 19: 
					command("nono");
					tell_object(ob, "$HIMӺ��һ�����ߺ��������������㣬�㡣����");
					break;
				case 20: 
					command("cry");
					command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ҳ��һ����̬��", query_rude(ob)));
					break;
				case 21: 
					command("blush");
					command(snprintf(msg, 255, "chat 0 С���������%s��Ҫ�����ң�", ob->name(1))) ;
					break;
				case 22: 
					command("nono");
					command("cry");
					break;
				case 23: 
					command("hate");
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 24: 
					command("careful");
					break;
				case 25: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					break;
				case 26:
					command("nono");
					command("faint");
					break;
				case 27: 
					command(snprintf(msg, 255, "grpfight %ld", ob->object_id()));
					break;
				case 28: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ȼ��һ������å��", query_rude(ob)));
					break;
				case 29: 
					command(snprintf(msg, 255, "rascal %ld", ob->object_id()));
					command(snprintf(msg, 255, "die %ld", ob->object_id()));
					break;
				case 30:
					command(snprintf(msg, 255, "waggle %ld", ob->object_id()));
					break;
				case 31:
					command("waggle");
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 32: 
					command(snprintf(msg, 255, "chat 0 �����˰������Ҵ�%s�����ɫħ��", ob->name(1)));
					break;
				case 33: 
					command(snprintf(msg, 255, "chat 0 ��Ӵ����Ӵ��%s��%s����ʵ��", ob->name(1), query_rude(ob)));
					command(snprintf(msg, 255, "shit %ld", ob->object_id()));
					break;
				case 34:
					command(snprintf(msg, 255, "chat 0 С���������%s��Ҫ�����ң�", ob->name(1))) ;
					command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ҳ��һ����̬��", query_rude(ob)));
					command(snprintf(msg, 255, "faint %ld", ob->object_id()));
					break;
				case 35: 
					command(snprintf(msg, 255, "kick %ld", ob->object_id()));
					command("grin");
					break;
				case 36:
					command(snprintf(msg, 255, "slap %ld", ob->object_id()));
					command("hehe");
					break;
				case 37: 
					command("faint");
					break;
				case 38: 
					command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ҳ��һ����̬��", query_rude(ob)));
					command(snprintf(msg, 255, "callname %ld", ob->object_id()));
					break;
				case 39: 
					command("!!!");
					break;
				default:
					if( random(10) < 3 )
					{
						command(snprintf(msg, 255, "%s %ld", verb.c_str(), ob->object_id()));
						return;
					}
					else	
					{ 
						command(snprintf(msg, 255, "chat 0 С���������%s��Ҫ�����ң�", ob->name(1))) ;
						command(snprintf(msg, 255, "chat 0 ��Ӵ��˭��õ���%s����Ҳ��һ����̬��", query_rude(ob)));
						tell_object(ob, "$HICӺ�ݺ�Ȼ����˵���򵹳���̶����С�䣡");
						command("cry");
						command(snprintf(msg, 255, "faint %ld", ob->object_id()));
					}
					break;
				}
			}
			else if(verb == "love" || verb == "lovelook" || verb == "praise" 
				|| verb == "visite" || verb == "drinkcup" || verb == "goodkid"
				|| verb == "pat" || verb == "addoil" || verb == "laughproud"
				|| verb == "smile" || verb == "xixi" || verb == "hehe"
				|| verb == "giggle" || verb == "thumb" || verb == "admire"
				|| verb == "applaud" || verb == "hi")
			{
				switch(random(35))
				{
				case 0: 
					command(snprintf(msg, 255, "pat %ld", ob->object_id()));
					break;
				case 1: 
					command("humble");
					break;
				case 2: 
					command(snprintf(msg, 255, "praise %ld", ob->object_id()));
					break;
				case 3: 
					command("xixi");
					break;
				case 4: 
					command(snprintf(msg, 255, "chat 0 %s�����µ�һ����ˣ�", ob->name(1)));
					command(snprintf(msg, 255, "giggle %ld", ob->object_id()));
					break;
				case 5: 
					command(snprintf(msg, 255, "goodkid %ld", ob->object_id()));
					break;
				case 6: 
					command(snprintf(msg, 255, "pat %ld", ob->object_id()));
					break;
				case 7: 
					command(snprintf(msg, 255, "chat 0 %s���������õ����ˣ�", ob->name(1)));
					command("giggle");
					break;
				case 8:
					command(snprintf(msg, 255, "praisemapi %ld", ob->object_id()));
					break;
				case 9:
					command(snprintf(msg, 255, "laughproud %ld", ob->object_id()));
					break;
				case 10:
					command(snprintf(msg, 255, "chat 0 �ţ�%s����Ŭ������", ob->name(1)));
					command("thank");
					break;
				case 11: 
					command("nod");
					command("xixi");
					break;
				case 12:
					command("shake");
					break;
				case 13:
					command(snprintf(msg, 255, "chat 0 �ţ�%s����Ŭ������", ob->name(1)));
					command(snprintf(msg, 255, "courage %ld", ob->object_id()));
					break;
				case 14: 
					command("xixi");
					break;
				case 15:
					command(snprintf(msg, 255, "lovelook %ld", ob->object_id()));
					break;
				case 16:
					command(snprintf(msg, 255, "smile %ld", ob->object_id()));
					break;
				case 17:
					command(snprintf(msg, 255, "chat 0 �ţ��Һ�ϲ��Ү��", ob->name(1)));
					command(snprintf(msg, 255, "kiss %ld", ob->object_id()));
					break;
				case 18:
					command(snprintf(msg, 255, "addoil %ld", ob->object_id()));
					break;
				case 19:
					command("xixi");
					break;
				case 20:
					command(snprintf(msg, 255, "shakehand %ld", ob->object_id()));
					break;
				case 21:
					command(snprintf(msg, 255, "courage %ld", ob->object_id()));
					break;
				case 22:
					command(snprintf(msg, 255, "touch %ld", ob->object_id()));
					break;		
				case 23:
					command("humble");
					break;
				case 24:
					command(snprintf(msg, 255, "protect %ld", ob->object_id()));
					break;
				case 25:
					command(snprintf(msg, 255, "thumb %ld", ob->object_id()));
					break;
				case 26:
					command("applaud ");
					command("giggle ");
					break;
				case 27:
					command("hi");
					break;
				case 28:
					command(snprintf(msg, 255, "hi %ld", ob->object_id()));
					break;
				case 29:
					command("chat 0 ����ô������");
					command("angry");
					break;
				default:
					command(snprintf(msg, 255, "chat* %ld %s", ob->object_id(), verb.c_str()));
					command("smile");
					break;
				}
			return;
			}
		}
	}
	return;
}

void drool(string msg, string who)
{
}
/*
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) 
	{
                if (random(10)<7)
                        command("chat ��ô��Ҷ���˵���ˣ����ǻ�������\n");
                else if (random(10)<8)
                        command("chat " +  rnd_say[random(sizeof(rnd_say))]);
                return;
	}

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}
	if(random(5)<2)
    {
	if(this_object()->query("killed")!=who)
	this_object()->set("killed",who);
	}
	while (this_object()->query("killed")==this_object()->query("killer"))
    {
	if(random(10)<2)
    {
		if(this_object()->query("killer")!=this_object()->query("killed"))
		this_object()->set("killer",who);
	}
	else switch(random(10))
    {
    case 1:	this_object()->set("killer","����");break;
	case 2:	this_object()->set("killer","����ɮ��");break;
	case 3:	this_object()->set("killer","����");break;
	case 4:	this_object()->set("killer","������");break;
	case 5:	this_object()->set("killer","����");break;
	case 6:	this_object()->set("killer","����");break;
	case 7:	this_object()->set("killer","Ӻ��");break;
	case 8:	this_object()->set("killer","������");break;
	case 9:	this_object()->set("killer","����");break;
	}
    }
	if( (strsrch(msg, "liling") >= 0)||(strsrch(msg, "Ӻ��") >= 0))
	{	
	if((strsrch(msg, "���") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "ɢ") >= 0)|| (strsrch(msg, "��") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s�ټ�%s", msg) == 2 ) msg = "�ټ�" + msg;
		if( sscanf(msg, "%*s���%s", msg) == 2 ) msg = "���" + msg;
		switch(random(13)) {
		case 0:	command("chat "+who+",�����Ҫ����\n"); break;
		case 1:	command("chat �㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ǹ�����,MUD�����û�ô�.\n"); break;
		case 3:	command("chat* Ӻ�ݵ��˵�ͷ.\n");	break;
		case 4:command("chat* Ӻ�ݺ����������.\n"); break;
		case 5:command("chat* Ӻ��������޺���۾�����ŵ��� "+who+",����Ҫ���˾ͱ��ٻ�����\n"); break;
		case 6:	command("chat* Ӻ�������̾��һ���� ��\n");	break;
		case 7:	command("chat "+who+",����һ����ò���?\n");	break;
		case 8:	command("chat "+msg);	break;
		case 9:command("chat �ޣ�"+who+"���������õ�����!\n"); break;
		}
		return;
	}
	if( (strsrch(msg, "kiss") >= 0)|| (strsrch(msg, "love") >= 0)|| (strsrch(msg, "��") >= 0)
		|| (strsrch(msg, "mo") >= 0)|| (strsrch(msg, "��") >= 0)|| (strsrch(msg, "hug") >= 0))
		{
		if( sscanf(msg, "%*skiss%s", msg) == 2 ) msg = "kiss" + msg;
		if( sscanf(msg, "%*smo%s", msg) == 2 ) msg = "mo" + msg;
		if( sscanf(msg, "%*shug%s", msg) == 2 ) msg = "hug" + msg;
		if( sscanf(msg, "%*slove%s", msg) == 2 ) msg = "love" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s��", msg) == 2 ) msg = "��"+ msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",�㡣����\n"); break;
		case 1:	command("chat �㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ҳ�ͬ�⣡\n");break;
		case 3:command("chat* Ӻ�ݱ�"+who+"�������˹�ȥ��\n"); break;
		case 4:command("chat* Ӻ�ݺ����������.\n"); break;
		case 5:command("chat ��Ҫ�������\n"); break;
		case 6:command("chat ���񰡷���"+who+"��С��å��������\n"); break;
		case 7:command ("chat С���������"+ who + "��Ҫ�����ң�\n") ;
		case 8:	command("chat* Ӻ��������Ц�˼���.\n"); break;
		case 9:	command("chat* Ӻ�ݺ������ؾ��˾��졣\n");	break;
		case 10:command("chat* Ӻ�����ε������ʼ�.\n");	break;
		case 11:command("chat ���Ů��������������\n"); break;
		case 12:command("chat �������ô������\n"); break;
		case 13:command("chat* Ӻ����ȻһЦ��˵�����˹���!\n"); break;
		case 14:command("chat* Ӻ�������͵�ͨ�죬�������㡣���� ��\n");	break;
		case 15:command("chat �ţ�"+who+"���������õ����ˣ�\n"); break;
	                case 16:command ("chat С���������"+ who + "�۸��ң�\n") ; break;
		}
		return;
	}
	if( (strsrch(msg, "��") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "shit" + msg;
		switch(random(15)) {
		case 0:	command("chat ����˵" + msg + "��\n"); break;
		case 1:	command("chat �ѵ���˵����....��\n");	break;
		case 2:	command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
		case 3:	command("chat* Ӻ�ݺ������ؾ��˾��졣\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5:	command("chat �Ҿ������е�����Ӳ��塣\n"); break;
		case 6:	command("chat ����˵�ɱ���Ҳ�������\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 8:	command("chat "+ who+",�������������е�����ͷ��������\n"); break;
		case 9:	command("chat* Ӻ�ݱ��ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 10:command("chat* Ӻ�ݱ�"+who+"�������˹�ȥ��\n"); break;
		case 11:command("chat* Ӻ�ݺ�Ȼ����˵���򵹳���̶����С�䣡\n"); break;
		case 12:command("chat* Ӻ��������޺���۾�����ŵ��� "+who+",�Һ������ˣ�\n"); break;
		case 13:command ("chat С���������"+ who + "����Ҫ�����ң�\n") ; break;
		}
	}
	if(  (strsrch(msg, "fool") >= 0)||(strsrch(msg, "��") >= 0)|| (strsrch(msg, "��") >= 0))
	{	
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sfool%s", msg) == 2 ) msg = "fool" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		switch(random(15)) {
		case 0:	command("chat �������ô������\n"); break;
		case 1:	command("chat �ҿ����������ܻ���\n");	break;
		case 2:	command("chat "+ who +",���������å��\n"); break;
		case 3:	command("chat* Ӻ��������ס���ӣ�˵��"+who+"˵���ó�!\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5:	command("chat �Ҿ������е�����Ӳ��塣\n"); break;
		case 6: command("chat ��!\n"); break;
		case 7:	command("chat* Ӻ��ŭ��:����ô֪����" + msg + "����\n"); break;
		case 8:	command("chat "+ who+"������!��Ҫ����������е�����ͷ��������\n"); break;
		case 9:	command("chat* Ӻ�ݱ��ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 10:command("chat* Ӻ�ݺ����������.\n"); break;
		case 11:command("chat* Ӻ��������޺���۾�����ŵ��� "+who+"���˵����ҹ���ȥ��\n"); break;
		case 12:command("chat ���񰡷���"+who+"�Ǹ����˵���\n"); break;
		}
		return;
	}
	if(  (strsrch(msg, "cool") >= 0)||(strsrch(msg, "praise") >= 0)|| (strsrch(msg, "admire") >= 0))
	{	
		if(random(5)<3)
        {
		switch(random(15)) {
		case 0:	command("chat �������ô������\n"); break;
		case 1:	command("chat ������˵����\n"); break;
		case 2:	command("chat "+who+",û�뵽��Ҳ��ô������\n"); break;
		case 3:	command("chat* Ӻ����ȻһЦ��˵������!\n"); break;
		case 4:	command("chat �������Ϊ��" + msg + "����\n"); break;
		case 5: command("chat* Ӻ�ݺ�Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
		case 6:    command("chat* Ӻ�ݻ�ͷ����"+who+"һ�ۣ�û������\n");break;
		case 7: command("chat ��,"+who+"��һ���ú���.\n"); break;
		case 8:command("chat "+who+",�㲻�������ֺ��Ұ�?\n"); break;
		case 9:command("chat* Ӻ�ݹ��˹��ֵ������������� !\n");break;
		case 10:command("chat* Ӻ��ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
		}
		return;
        }
	}
	switch(random(80)) {
		case 0:	command("chat �������˵" + msg + "��\n"); break;
		case 1:	command("chat ��Ϊʲô������ô����Ȥ��\n");	break;
		case 2:	command("chat ���㡰" + msg + "������������ô���أ�\n"); break;
		case 3:	command("chat ��,��" + msg + "������Ҳû��ϵ.\n"); break;
		case 4:	command("chat "+who+",���������å��\n"); break;
		case 5:	command("chat ����˵���ǣ�"+"��ʵ"+who+"���Ǹ��ö�����\n"); break;
		case 6:	command("chat ������˵�ġ�" + msg + "��������ʱ�����̬��\n"); break;
		case 7:	command("chat ����Ϊ���̬�Ȳ����Ү.\n"); break;
		case 8:	command("chat ��ע�⣬��ֻ�ǻ�����Ү!\n"); break;
		case 9:	command("chat ���Ů��������������\n"); break;
		case 10:	command("chat ��Ҫ�������Һò��ã�\n");	break;
		case 11:	command("chat �����ҿ������������顣\n");	break;
		case 12:	command("chat* Ӻ�������̾��һ���� ��\n");	break;
		case 13:	command("chat* Ӻ�ݱ�"+who+"�������˹�ȥ ��\n");	break;
		case 14:	command("chat* Ӻ�������͵�ͨ�죬�������㡣���� ��\n");	break;
		case 15:    command("chat* Ӻ��ҧ��ҧ����ŭ��: �ţ�˭Ҫ�ٸ��۸��ң��Ҿ���������\n");break;
		case 16:    command("chat* Ӻ�ݺ�Ȼݸ��һЦ��: �������Ǻο��أ�\n");break;
		case 17:    command("chat* Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n"); break;
		case 18:    command("chat* Ӻ�ݻ�ͷ����"+who+"һ�ۣ�û������\n");break;
		case 19:    command("chat* Ӻ��һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
		case 20:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 21:	command("chat �Ҿ���"+who+"���˼�ֱ����������\n"); break;
		case 22:	command("chat ������˵����\n"); break;
		case 23:	command("chat "+who+",û�뵽��Ҳ������\n"); break;
		case 24:	command("chat* Ӻ����ȻһЦ��˵������!\n"); break;
		case 25:	command("chat ��Ȼ������������!\n");
		 	command("chat* Ӻ�ݺ����������.\n"); break;
        case 26:	command ("chat С���������"+ who + "���������ң�\n") ; break;
      	case 27:	command ("chat �Ҽ�ֱ�ܲ�����!\n") ; break;
        case 28:	command ("chat �Һ޲���"+who+"ȥ��!\n") ; break;
        case 29:	command ("chat �����Ϻ��ҹ���ȥ!\n") ; break;
        case 30:	command ("chat �벻Ҫ�����Һò���?\n") ; break;
   		case 31:	command ("chat* Ӻ�������̲�ס����������\n") ; break;
		case 32:	command("chat* Ӻ�ݱ��ĵؿ���"+who+",�޲���"+who+"ȥ����\n"); break;
		case 33:    command("chat* Ӻ��ҧ��ҧ����ŭ��: �ţ�˭Ҫ���۸��ң��Ҿ���������\n");break;
		case 34:    command("chat* Ӻ�ݺ�Ȼݸ��һЦ��: �����ǲ����е����������\n");break;
		case 35:    command("chat* Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ������������е�����ˡ�\n"); break;
		case 36:    command("chat* Ӻ�ݻ�ͷ����"+who+"һ�ۣ�û������\n");break;
		case 37:    command("chat* Ӻ��һ˦ͷ��˵���ߣ��Ҷ��������㡣\n");break;
		case 38:    command("chat ��" + msg + "��,�������\n"); break;
		case 39:    command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
		case 40:    command("chat ����ȥ��������.\n"); break;
		case 41:    command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
		case 42: command("chat* Ӻ��Ц�����Ŀ���"+who+"\n"); break;
		case 43: command("chat �����ģ�������!\n"); break;
		case 44: command("chat �ߣ�\n"); break;
		case 45: command("chat* Ӻ�ݴ���"+who+"һ������.\n"); break;
		case 46: command("chat �ߣ�˭���㰡!\n");break;
		case 47: command("chat ��,"+who+"��һ���ú���.\n"); break;
		case 48:command("chat* Ӻ��¶���Ի�ı���.\n"); break;
		case 49:command("chat ����?\n"); break;
		case 50:command("chat "+who+",���ǲ������ֺ��Ұ�?\n"); break;
		case 51:command("chat ��,˭��˵�һ���?!\n");break;
		case 52:command("chat �㲻�ǿ���Ц��?\n");	break;
		case 53:command("chat �Ҳ�ͬ�⣡\n");break;
		case 54:command("chat* Ӻ�ݶ�"+who+"��ʾ���ĵĸ�л.\n");break;
		case 55:command("chat ��Ҫ�������\n"); break;
		case 56:command("chat* Ӻ�ݹ��˹��ֵ������������� !\n");break;
		case 57:command("chat* Ӻ��ŭ��:����ô֪����" + msg + "����\n"); break;
		case 58:command("chat* Ӻ��ָ��"+who+"��̾������"+who+"�����ֵ�һ���֣���\n");break;
		default:
	    if (random(10)<3) command("chat* Ӻ�ݺ������ؾ��˾���.\n"); 
	    else if(random(10)<3) command("chat* Ӻ��������Ц�˼���.\n");
	    break; 
		}
	return;
	} 
	if( (strsrch(msg, "��") >= 0))
	{	
	   if(random(5)<3)
        {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		switch(random(15)) {
		case 0:	command("chat "+who+",����Ŀ���?\n"); break;
		case 1:	command("chat �Ҳ���Ү.\n");	break;
		case 2:	command("chat* Ӻ��������Ц�˼���.\n"); break;
		case 3:command("chat* Ӻ��¶���Ի�ı���.\n"); break;
		case 4:command("chat* Ӻ�ݺ����������.\n"); break;
		case 5:command("chat* Ӻ�ݰ�ο"+who+",���ѹ���.\n"); break;
		case 6:	command("chat* Ӻ�������̾��һ���� ��\n");	break;
		case 7:	command("chat* Ӻ�����ε������ʼ�.\n");	break;
		case 8: command("chat* Ӻ������������"+who+"��ͷ.\n"); break;
		}
		return;
        }
	}
	if( (strsrch(msg, "���") >= 0)||(strsrch(msg, "bye") >= 0)|| (strsrch(msg, "ɢ") >= 0)|| (strsrch(msg, "��") >= 0))
	{	
		if( sscanf(msg, "%*sbye%s", msg) == 2 ) msg = "bye" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sɢ%s", msg) == 2 ) msg = "ɢ" + msg;
		if( sscanf(msg, "%*s���%s", msg) == 2 ) msg = "���" + msg;
		switch(random(20)) {
		case 0:	command("chat "+who+",�����Ҫ����\n"); break;
		case 1:	command("chat "+who+"�㲻�ǿ���Ц��?\n");	break;
		case 2:	command("chat �Ǹ�����,MUD�����û�ô�.\n"); break;
		case 3:	command("chat* Ӻ�ݵ��˵�ͷ.\n");	break;
		case 4:command("chat* Ӻ�ݺ����������.\n"); break;
		case 5:command("chat* Ӻ��������޺���۾�����ŵ��� "+who+",����Ҫ���˾ͱ��ٻ�����\n"); break;
		case 6:	command("chat* Ӻ�������̾��һ���� ��\n");	break;
		case 7:	command("chat "+who+",����һ����ò���?\n");	break;
		case 8:	command("chat "+msg+"\n");	break;
		case 9:	command("chat* Ӻ�����ε������ʼ�.\n");	break;
		}
		return;
	}
	if( (strsrch(msg, "��") >= 0)||(strsrch(msg, "shit") >= 0)||(strsrch(msg, "pig") >= 0))
	{	
		if( sscanf(msg, "%*spig%s", msg) == 2 ) msg = "pig" + msg;
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*sshit%s", msg) == 2 ) msg = "��" + msg;
		if(random(5)<3)
        {
		switch(random(25)) {
		case 0:	command("chat ����˵" + msg + "��?\n"); break;
		case 1:	command("chat Ϊʲô��?\n");	break;
		case 2:	command("chat " + who + ",������ !!\n"); break;
		case 3:	command("chat* Ӻ�ݺ������ؾ��˾��졣\n");	break;
		case 4:	command("chat �������Ϊ��" + msg + "��?\n"); break;
		case 5:	command("chat �Ҿ���������������е��������\n"); break;
		case 6:	command("chat ������˵�ġ�" + msg + "��������ʱ�����̬��\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ���, �͵���Ϊֹ��.\n"); break;
		case 8:	command("chat "+who+",��˵˭����\n");	break;
		case 9:	command("chat ���㡰" + msg + "�������ִ�����ô���أ�\n"); break;
		case 10:	command("chat �Ҳ���Ү.\n");	break;
		case 11:	command("chat* Ӻ��������Ц�˼���.\n"); break;
		case 12:	command("chat* Ӻ�ݰѰ�ͷҡ�ø����˹��Ƶ�.\n");	break;
		case 13:	command("chat* Ӻ�ݹ�����Ц����.\n"); break;
		}
		return ;
        }
	} 
	else if( (strsrch(msg, "Ϊʲ��") >= 0)|| (strsrch(msg, "why") >= 0)
		|| (strsrch(msg, "help") >= 0)|| (strsrch(msg, "how to") >= 0)|| (strsrch(msg, "how to") >= 0)) {
		if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
		if( sscanf(msg, "%*swhy%s", msg)==2 ) msg = "why" + msg;
		if( sscanf(msg, "%*show to%s", msg)==2 ) msg = "how to" + msg;
		if( sscanf(msg, "%*swho%s", msg)==2 ) msg = "who" + msg;
		if( sscanf(msg, "%*shelp%s", msg)==2 ) msg = "help" + msg;
		switch(random(30)) {
		case 0: command("chat " + who + "��������������?\n"); break;
		case 1: command("chat ��춡�" + msg + "�� ... \n"); break;
		case 2: command("chat �� ... \n"); drool(); break;
		case 3: command("chat ��������� ....\n"); break;
		case 4: command("chat " + who + "��֪���������Ĵ𰸶���������Ҫ��\n"); break;
		case 5: command("chat ��" + msg + "��?\n"); break;
		case 6: command("chat " + who + "���ܲ���˵���һ�㣿\n"); break;
		case 7: command("chat " + who + "���Ҳ������ʵ����⡣\n"); break;
		case 8: command("chat " + who + "����û�����?\n"); break;
		case 9: command("chat �ţ����������ҿ������������Լ������\n"); break;
		case 10: command("chat ˭���"+who+"һ���Ǯ?\n"); break;
		case 11: command("chat �����Ķ�?\n"); break;
		case 12: command("chat* Ӻ������������"+who+"��ͷ.\n"); break;
		case 13: command("chat ��������,������!\n"); break;
		}
 	return;
               }
	else if( (strsrch(msg, "��") >= 0)
	||	(strsrch(msg, "you") >= 0)) {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		switch(random(30)) {
		case 0:	command("chat " + who + "���������˵" + msg + "��?\n");	break;
		case 1:	command("chat ��ȷ��" + msg + "?\n");	break;
		case 2:	command("chat " + msg + "������ʲ���ϵ��\n");	break;
		case 3:	command("chat �� ... " + who + "˵�úã�\n"); break;
		case 4:	command("chat " + who + "��Ϊʲ���" + msg + "��������Ȥ?\n"); break;
		case 5:	command("chat Ϊʲ�������Ϊ[" + msg + "]?\n"); break;
		case 6:	command("chat ��������ò���?\n"); drool(); break;
		case 7:	command("chat �Ź�!\n"); break;
		case 8:	command("chat ��һ����?\n"); break;
		case 9:	command("chat ������������� ....\n"); break;
		case 10:	command("chat �Ҳ��� ....\n"); break;
		case 11:	command("chat �ҶԴ������.\n"); break;
		case 12:	command("chat* Ӻ�������̾��һ����. \n");	break;
		case 13:	command("chat* Ӻ�ݹ�����Ц����.\n"); break;
		}
	return;
	}
	if( (strsrch(msg, "Ц") >= 0))
	{	
		if( sscanf(msg, "%*sЦ%s", msg)==2 ) msg = "Ц" + msg;
		if(random(5)<4)
        switch(random(20)) {
		case 0:	command("chat �ܺ�Ц��\n"); break;
		case 1:	command("chat "+who+",���ϲ��Ц�ǲ��ǣ�\n");	break;
		case 2:	command("chat �ҿ�������ʲô��Ц.\n");	break;
		case 3:	command("chat "+who+"Ц�������\n"); 
			if(random(10)<2) command("chat* Ӻ��������Ц�˼���.\n");break;
		case 4:	command("chat* Ӻ�ݿ�����Ц������.\n");break;
		case 5:	command("chat* Ӻ�ݸ��˵���������.\n");break;
		case 6: command("chat* Ӻ������������"+who+"��ͷ.\n"); break;
		case 7:	command("chat* Ӻ�ݹ�����Ц����.\n"); break;
		case 8: command("chat* Ӻ��˵��:ͬϲ,ͬϲ!!!\n" );break;
	}
	} 
	else if( (strsrch(msg, "��") >= 0)|| (strsrch(msg, "I") >= 0)||(strsrch(msg, "i") >= 0)) {
		if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
		if( sscanf(msg, "%*s i %s", msg) == 2 ) msg = " i " + msg;
		if( sscanf(msg, "%*s I %s", msg) == 2 ) msg = " I " + msg;
		msg = replace_string(msg, "��", "��");
		msg = replace_string(msg, " i ", " you ");
		msg = replace_string(msg, " I ", " you ");
		msg = replace_string(msg, "?", "");
		switch(random(30)) {
		case 0:	command("chat ����˵" + msg + "��?\n"); break;
		case 1:	command("chat ���?" + msg + "?\n");	break;
		case 2:	command("chat ���" + msg + "�����ܰ���ʲ��æ��?\n");	break;
		case 3:	command("chat "+msg+" ?�ҿ�δ��.\n");	break;
		case 4:	command("chat ����Ϊ" + msg + "?\n"); break;
		case 5:	command("chat ����ͬ��.\n"); break;
		case 6:	command("chat ��˵�ġ�" + msg + "����ʵ�ڲ��ܹ�ͬ.\n"); break;
		case 7:	command("chat �йء�" + msg + "���Ļ��⵽��Ϊֹ����?\n"); break;
		case 8:	command("chat ��һ���ɣ�\n"); break;
		case 9:	command("chat ��������� ....\n"); break;
		case 10:command("chat �Ҳ��� ....\n"); break;
		case 11:drool(); break;
		case 12:drool(); break;
		case 13:command("chat* Ӻ��������Ц�˼���.\n"); break;
		case 14:command("chat* Ӻ��ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
		case 15:command("chat �ҶԴ˱�ʾ����.\n"); break;
		case 16:command("chat* Ӻ�������̾��һ���� ��\n");	break;
		case 17:command("chat* Ӻ��¶���Ի�ı���.\n"); break;
		case 18:command("chat ����?\n"); break;
 		}
	} 
else {
		switch(random(250)) {
			case 0: command("chat �Ҳ�ϲ����˵��" + msg+"��.\n"); break;
			case 1: command("chat ��" + msg + "����ʲ����˼��\n"); break;
			case 2: command("chat* Ӻ�ݡ��ߡ�����Цһ����\n"); break;
			case 3: command("chat* Ӻ������������������\n"); break;
			case 4: command("chat* Ӻ���������˹�ȥ.\n"); break;
			case 5: command("chat  �ߣ�\n"); break;
			case 6: command("chat* Ӻ��¶���Ի�ı���.\n"); break;
			case 7: command("chat* Ӻ�ݺ�Ȼ���˸�����,˵�������ȥ����.\n"); break;
			case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("chat ������֪��" + msg + "?\n"); break;
			case 10: command("chat �ո�" + who + "����˵�ˣ�" + msg); break;
			case 11: command("chat* Ӻ�ݺ��������������졣\n"); break;
			case 12: command("chat Ȼ���أ�\n"); break;
			case 13: command("chat �����\n"); break;
			case 14: command("chat �Ҳ�������Ϊ��\n"); break;
			case 15: command("chat �Բ���,�Ҳ�ͬ����Ĺ۵㡣\n"); break;
			case 16: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
			case 17: command("chat �����������ط�!\n"); break;
			case 18: command("chat* Ӻ��ҡͷ̾���������������Ǹ�����ɨ��ǰѩ���ݹ���������˪.\n");break;
			case 19: command("chat* Ӻ������һ��Ҿ��˵��������λ�����ǣ���Һã���\n");break;	
			case 20: command("chat ��֪���ˣ�" + msg+"\n"); break;
			case 21:command("chat* Ӻ��¶���Ի�ı���.\n"); break;
			case 22: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 23: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 24: command("chat " + rnd_say[random(sizeof(rnd_say))]); break;
			case 25: command("chat* Ӻ�����ĵ������־˵��һ���ˣ���û��˼��\n"); break;
			case 26: command("chat* Ӻ��¶���Ի�ı���.\n"); break;
			case 27: command("chat* Ӻ���û��ɵ��۹⿴�˿�"+who+"\n"); break;
			case 28: command("chat  �ҿ�δ��.\n"); break;
			case 29: command("chat* Ӻ�����������\n"); break;
			case 30: command("chat  ��ʦ������"+who+"�㻹���Ͽ�ȥ��\n"); break;
			case 31: command("chat "+who+",�������ô���ӿ�?\n"); break;
			case 32: command("chat* Ӻ�ݶ������ڳ����˱�ʾ��л��\n"); break;
			case 33: command("chat* Ӻ��������Ц�˼���.");break;
			case 34: command("chat "+who+"˵�ú�!"); break;
			case 35: command("chat* Ӻ�ݺ���ؿ���"+who+"\n"); break;
			case 36: command("chat "+who+",û�뵽��Ҳ������."); break;
			case 37: command("chat* Ӻ�ݰ���"+who+"һ��,˵:�����Ĳ����İ�?"); break;
			case 38:  command("chat* Ӻ�ݻ�ͷ����"+who+"һ�ۣ�û������\n");break;
			case 39:command("chat* Ӻ��ҡ��ҡͷ��̾�������������������£����Ĳ��Ű���\n"); break;
			case 40:command("chat �� ... " + who + "˵�úã�\n"); break;
			case 41:command("chat* Ӻ�����ε������ʼ�.\n");	break;
			case 42:command("chat �ţ�"+who+"���������õ����ˣ�\n"); break;
			case 43:command("chat* Ӻ�ݰѰ�ͷҡ�ø����˹��Ƶ�.\n");	break;
			case 44:command("chat �ҶԴ˱�ʾ����.\n"); break;
			case 45: command("chat �Ҿ�����ѱ��齱Ӧ������"+who+".\n"); break;
			case 46: command("chat* Ӻ������������"+who+"��ͷ.\n"); break;
			case 47: command("chat* Ӻ��Ц�����Ŀ���"+who+"\n"); break;
			case 48: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 49: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 50: command("rumor "+this_object()->query("killed")+"��"+this_object()->query("killer")+"ɱ����.\n"); break;
			case 51: command("chat �Ҿ���"+who+"�����ֻ�����.\n"); break;
			case 52: command("chat "+who+",���������å!\n"); break;
			case 53: command("chat �ţ�"+who+"�������Ǹ�����.\n"); break;
			case 54: command("chat �ߣ�\n"); break;
			case 55: command("chat* Ӻ�ݴ���"+who+"һ������.\n"); break;
			case 56:command("chat* Ӻ�ݸ����ӯӯ�ĸ���һ��.\n"); break; 
			case 57:command("chat ��Ҫ������!"); break; 
			case 58:command("chat Ҫ������!"+who+"!\n"); break; 
			case 59:command("chat* Ӻ�ݺ�Ȼ����˵���򵹳���̶����С�䣡\n"); break;
			case 60:command("chat* Ӻ��¶���Ի�ı���.\n"); break;
			case 61:command("chat* Ӻ����۸ߺ����������Ȱ������У����������꣡��\n");break;
			case 62:command("chat* Ӻ�ݶԴ��ҡҡͷ��̾���������Ƕ�̫��Ҫ���ˡ���\n");break;
			case 63:command("chat* Ӻ�ݵ��˵�ͷ.\n");	break;
			case 64:command("chat* Ӻ�ݹ�����Ц����.\n"); break;
			case 65: command("chat ��������,������!\n"); break;
			case 66:command("chat* Ӻ��ʧ������!\n");break;
			default:
	    if (random(10)<1) command("chat* Ӻ��������ü���ƺ���˵ʲô��\n");
		else if (random(10)<1) command("chat* Ӻ��������Ц�˼���.\n");
	    else if (random(10)<1) command("chat* Ӻ����������������.\n");
				break;
		}
	}
}

void reset()
{
	del("memory");
}
	
void init()
{       
object ob;
ob = this_player();
::init();
if (userp(ob))
if(random(10)>5)
add_action("do_tell", "tell");
add_action("do_name", "ɱ");
add_action("do_name2", "��");
add_action("do_sing", "sing");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision(	"$N��$n��ȻһЦ.\n\n",this_object(),ob );
if(ob->query("id")=="wind")
{
	  ob->set("qi",10000);
	  ob->set("jing",10000);
	  command("say �ޣ�"+ob->query("name")+"���ӻ����ˡ�");
}
else
{
command("say ��λ" + RANK_D->query_respect(ob)
+ "��Ե������СŮ�ӷ��У�\n");
if (ob->query("gender") == "����"||ob->query("gender") == "����")
{
       message_vision(
	HIM "$Nһ������Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"�������ٶ���ЦһЦ���Ҿ�������Ҳ�ĸʰ�!...\n" NOR,ob,this_object());
	command("say "+"��λ" + RANK_D->query_respect(ob)+"����ӭ���п���������");
	command("xixi");
}
else
{
       message_vision(
	HIM "$Nһ������Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"������Ҳ�����ӣ���Ҫ��Ϊ��ȥ������Ҳ������һ��ü...\n" NOR,ob,this_object());
	command("say �������������������ң��������ȴ����һλ" + RANK_D->query_respect(ob)+"\n");
}
}
}


int do_tell ( string arg )
{
   object ob ;
   string dir,dir2;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;

   if( arg=="liling" ) {
   message_vision("\nӺ�ݶ�$NЦ�������㷢�հ�����Ȼ��������˵������\n", ob);
   command("say �벻��"+ob->query("name")+"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
   command("tell "+ob->query("id")+" ���涺��");
   }
   if( sscanf(arg, "liling wind send me %s", dir2)==1 ) {
	ob->set_temp("windnod2",1);
	command("xixi");
	return 1;
   }
   if( sscanf(arg, "liling %s", dir)==1 ) {
		if( dir=="I love you"||dir=="��"||dir=="�Ұ���") {
		message_vision("\n$N��Ӻ�ݴ���˵�����Ұ��㣡\n", this_player());
		if(ob->query("id")=="wind")
		{
		command("tell "+ob->query("id")+" �ҿɲ���ôϲ���㡣");
		command ("kiss "+ob->query("id"));
		command("follow "+ob->query("id"));
		return 1;
		}
		else
		{
		command("tell "+ob->query("id")+" �㾡���Ը������ɡ��ҾͶ�С������Ȥ��");
		command("tell "+ob->query("id")+" ����ɵ��");
		command("hit "+ob->query("id"));
		return 1;
		}
		}
		if(dir=="no love"||dir=="����" ) {
		if(ob->query("id")=="wind")
		{
		message_vision("\n$N��Ӻ��˵�����Ҳ���������\n", this_player());
		command("cry");
		command("follow none");
		command("slap "+ob->query("id"));
		message_vision("\nӺ�ݶ�$N�޵����Һ�����������Ķ��������㣡\n", this_player());
		command("give "+ob->query("id")+" yu");
		command("give "+ob->query("id")+" ring");
		return 1;
		}
		else
		{
		message_vision("\nӺ�ݶ�$NЦ��Ц�������Ͳ����¡�\n", this_player());
		command("tell "+ob->query("id")+" ����ɵ��");
		command("xixi");
		return 1;
		}
		}
    message_vision("\nӺ�ݶ�$NЦ�������㷢�հ�����Ȼ��������˵������\n", ob);
    command("say �벻��"+ob->query("name")+"��" + RANK_D->query_rude(ob)+"����Ȼ��һ����̬��");
    command("tell "+ob->query("id")+" ���涺��");
    return 1;
    }
return 0;
}

int do_chat( string arg )
{
   object ob ;
   string dir;
   ob = this_player() ;
   if( !arg || arg=="" ) return 0;
   if( sscanf(arg, "kiss %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"
		+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "taste %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��ѽ��"+ob->query("name")+"��"
		+ RANK_D->query_rude(ob)+"��Ȼ�����Ҿ�����ˮ������ģ�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
		return 1;
		}
	}
   if( sscanf(arg, "mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "18mo %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
command("chat ��������"+ob->query("name")+"��ͷ"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�����ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
   if( sscanf(arg, "hug %s", dir)==1 ) {
		if( dir=="liling") {
		if(ob->query("id")=="wind") return 0;
		else
		{
		command("chat ��������"+ob->query("name")+"��"+ RANK_D->query_rude(ob)+"��Ȼ�뵱�ڱ��ң�\n");
		command("xixi");
			if(wizardp(ob))		
	                { 
			ob->set("immortal",0);
			command("aim "+ob->query("id"));
			command("shoot");
                	}
			this_object()->kill_ob(ob);
		}
                return 1;
		}
	}
return 0 ;
}

int do_sing ( string arg )
{
   object ob ;
   string dir;
   ob = this_player();
   if( !arg || arg=="" ) return 0;
   if( arg=="for" ) return notify_fail("����Ϊ˭����?\n");
   if( sscanf(arg, "for %s", dir)==1 ) {
		if( dir=="liling" ) {
 	        message_vision("\n$N��Ӻ�ݳ������������\n", this_player());
		switch(random(2))
		{
		case 1:
		message_vision(	"$N��$n��ȻһЦ.\n\n",this_object(),ob );
		ob->set_temp("windnod",1);
		break;
		default:
		message_vision("\nӺ�ݶ�$NЦ�������㷢���հ�����Ȼ�Ի����˳��衣��\n", ob);
		command("tell "+ob->query("id")+" �㾡���Ը������ɣ��Ҳ�Ҳ�����㡣");
		command("tell "+ob->query("id")+" ���涺��");
		command("kick "+ob->query("id"));
		command("giggle");
		break;
		}
	return 1;
	}	
else return notify_fail("\n����ֻ����ΪӺ�ݶ���----С��\n");
}
return 0 ;
}

void die()
{
	object ob;
	command("cry");
	message_vision("\n$N����һ������˵����С���Ϊ�ұ���ġ�\n", this_object());
	message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
	ob = new("/d/city2/obj/shouzhuo");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/yupei");
	ob->move(environment(this_object()));
	ob = new("/d/city2/obj/crystal");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/ring");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/majia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/baojia");
	ob->move(environment(this_object()));
	ob= new("/d/city2/obj/bishou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

void defeated_enemy(object victim)
{
command("nomatch");
}

int accept_fight(object who)
{
message_vision("\n$Nҡ��ҡͷ����$n����̾���������������Ǻο���?\n",this_object(),who);
command("nomatch "+who->query("id"));
}

string ask_bf()
{
return("�ף���Ҳ֪��������Ҳ���������������\n ");
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if (ob->query("money_id") && ob->value() >= 1000000 )
	{
 	        if(me->query_temp("windnod"))
		{
		tell_object(me, "\nӺ����ȻһЦ��˵���ðɣ���ȻС������������Ҿ�����ġ�\n");
		tell_object(me, "����룺ɱ Ŀ����������\n");
		me->delete_temp("windnod");
		me->set_temp("fee_paid",1);
		return 1;
		}
		else 
		{
		say("\nӺ��ҡҡͷ��Ц�������ðɣ�ɱ�˵���С�䲻��ͬ��ġ�\n");
		me->set_temp("fee_paid2",1);
		tell_object(me, "\nӺ����ȻһЦ��˵���������ҿ��Կ���С��Ц��\n");
		tell_object(me, "����룺�� Ŀ����������\n");
		return 1;
		}
	}
	else if (ob->query("money_id") && ob->value() < 1000000) 
	{
		tell_object(me, "\nӺ��ҡҡͷ��Ц�������ðɣ����������Ǯ��\n");
		return 1;
	}

	if ((string)ob->query("name")==HIC "�����ָ" NOR ||(string)ob->query("name")==HIW "ˮ��Ь" NOR
		||(string)ob->query("name")==HIM "С���" NOR||(string)ob->query("name")==HIC "����" NOR) 
	{
	if ((string)ob->query("name")== HIC "�����ָ" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�ϲ���۹⿴��$n��˵��\n"
	+"�ף��ⲻ��С�����ҵĽ�ָ������Ҫ�������ô? ��лл�㰡...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIW "ˮ��Ь" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�ϲ���۹⿴��$n��˵��\n"
	+"�ף��ⲻ��С�����ҵ���ˮ��Ь������Ҫ�������ô? ��лл�㰡...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIM "С���" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�����۹⿴��$n��˵��\n"
	+"�ף��ⲻ���ҵ�С�������ô��...\n",this_object(),me);
	}
	if ((string)ob->query("name")==HIC "����" NOR) 
	{
	message_vision("\n$N�͵�����ͷ���þ�����۹⿴��$n��˵��\n"
	+"�ף��ⲻ���ҵ�������������ô��...\n",this_object(),me);
	}
	return 1; 
	}
	else
	{
	message_vision("\n$N������ҡ��ҡͷ������˵��:����С�����ҵ�,�Ҳ�Ҫ.\n"
	+"˵�մ���ͷ����ҧ��ҧ��,������������С�䣬��С�䣬Ϊʲô����������?\n",this_object());
	return 0;
	}
}

int do_name(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		return notify_fail("Ӻ�ݣ���������æ���ģ�������������ɣ�\n");
	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail("Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ���������\n"+
		"���ðɣ�����ɱ����������ʲô�ô��أ�\n");
	if( !target || target==" ")
		return notify_fail("Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ���������\n"
		+"����������˵����֣��ҿ�û����������ġ�\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("Ӻ�����˸���������̫�ð�������������ม�\n");

	if (dest->is_ghost())
		return notify_fail("Ӻ��˵����ڣ���̫�ڣ���̫̫�ڣ���̫̫̫�ڣ����Ѿ�������\n");
	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	me->delete("chat_chance");
	me->delete("chat_msg");
	message("vision",
	HIY "\nӺ����Ҫ�뿪�����ֻ��׵�������ߣ����������������ɡ�\n" NOR,
	environment(), me );
	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	me->set("bellicosity", 100000);
	message_vision("HIM $N���˳�ȥ��\n" NOR, me);
	call_out("do_chase", 1, me);
	return 1;
}

int do_name2(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();
	if(!this_player()->query_temp("fee_paid2") ) 
		return notify_fail("Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ���������\n"+
		"���ðɣ�������������ʲô�ô��أ�\n");
        if(!this_player()->query_temp("windnod2"))
		return notify_fail("\nӺ��ҡҡͷ��Ц�������ðɣ����˵���С�䲻��ͬ��ġ�\n");
        if( !target || target==" ")
		return notify_fail("Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ���������\n"
		+"����������˵����֣��ҿ�û����������ġ�\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("Ӻ�����˸���������̫�ð�������������ม�\n");
	if (dest->is_ghost())
		return notify_fail("Ӻ��˵����û�Ӵ�����Ѿ�������\n");
	me->set("waiting_target2", dest->query("id"));
        this_player()->delete_temp("windnod2");
        this_player()->delete_temp("fee_paid2");
	message("vision",
		HIM "\nӺ�������ڿڣ�Ц�����������������Ү������ôл��ѽ��\n" NOR,
		environment());
	call_out("do_faint", 1, me);
	return 1;
}

int do_chase(object me)
{
	
	object dest,room;
	dest = find_player(me->query("waiting_target"));
	if( !objectp(dest) || !environment(dest) )      
	{
		call_out("waiting", 0, me);
		return 1;
	}
	me->move(environment(dest));
	message_vision("$NЦ���������˹�����\n" NOR, me);
	room = environment(this_object());
	if (room->query("no_fight"))
		room->set("no_fight", 0l);

	me->set_leader(dest);
	command("look " + dest->query("id"));
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}


int do_faint(object me)
{
	
	object dest,ob;
	dest = find_player(me->query("waiting_target2"));
	this_object()->move(environment(dest));
	message_vision("$NЦ���������˹�����\n" NOR, me);
	message_vision(HIC "$N��$n˵�������������������㣬�Բ��𰡡�����\n"
			+RANK_D->query_rude(dest)+"����������ɣ�\n" NOR, me, dest);
        me->delete("waiting_target2");
        dest->unconcious();
	this_object()->move("/u/wind/workroom");
 	return 1;
}


int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N��$n˵����С��Ҫ����ɱ�㣬�Բ��𰡡�����\n"
			+RANK_D->query_rude(dest)+"����������ɣ�\n" NOR, me, dest);
			if(wizardp(dest))		
	                { 
			dest->set("immortal",0);
			command("aim "+dest->query("id"));
			command("shoot");
                	}
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);
		call_out("checking", 0,  me);   
	}
	else call_out("waiting", 1, me);     
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}               
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") == me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
	return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/u/wind/workroom");
	message("vision", "Ӻ�����˽��������ĵ�������С���治�ԣ���������ɱ���ˡ�\n", 
		environment(), me );
	me->set_leader(0);
	set("chat_chance", 3);
	set("chat_msg", ({
		"Ӻ�ݺ�Ȼ���˸�������Ц��: �������ȥ������\n",
		(: command("sing2") :),
		"Ӻ�����ĵ������־̾��: ����һ���ˣ���û��˼��\n",
		"Ӻ�����������һ���С�֣������°�˵: ˭�����˵˵��?\n",
		"Ӻ��ն��������˵: �ţ�˭Ҫ���۸��ң��Ҿ���������\n",
		"Ӻ�ݺ�Ȼݸ��һЦ��: С��������Ҫ��ɱ˭�أ�\n",
		"Ӻ�ݴ��˸���Ƿ������������סӣ��С�ڣ��������������ˡ�\n",
	}) );
	return 1;
}
*/
NPC_END;