/*
string *list1 = ({ "ɱ��", "ɱ��ͳ��", "ָ��ʹ", "���ܹ�", "�ܹ�" }); //-->���ø��ܹ�-->������ξ-->��������-->�����󽫾�
string *list2 = ({ "ϸ��", "ϸ��ͳ��", "ָ��ʹ", "���ܹ�", "�ܹ�" }); // ���ø��ܹ�-->��������-->������ʦ-->������

int do_shengji();
int kill_stranger( object who );
int kill_stranger1( object who );
int try_rutang();
int start_rutang( object me );
int do_jieshao( string arg );
int do_choose( string arg );
int do_lingpai( string arg );
string dir_random();
string to_english( string arg );
int read_task( object me );
int crash( object ob );
*/
//һƷ�������ܹ�

//yunying.c

//sound 2001-07-17

NPC_BEGIN(CNlingzhou_yunying);

virtual void create()
{
	set_name("������ӥ", "helian yunying");
	set("title", "һƷ�������ܹ�");
	set("gender", "����" );
	set("age", 45);
	set("str", 200);
	set("per", 30);
	set("icon",general);
	set("long", "����һƷ�õ��ܹܣ��Ǻ���ͭ�����ĸ��͹��ܵ��ֵܡ�����һƷ���ճ����¡�");
	set("combat_exp", 300000);
	set("social_exp", 120000);
	
//	set_inquiry("����", "(:do_shengji:)");
	set_inquiry("����", "���ñ����б���������������Ƽ�����");
	
	set("chat_chance", 1);

//	carry_object("zangqing_sipao" )->wear();
//	carry_object("xuese_pifeng" )->wear();
}

virtual char *chat_msg()
{
	return "������ӥ������Ц�ţ�һ��Ŀ��һ�е����ӡ�";
}
/*
void init()
{
	add_action("try_rutang","join");
	add_action("do_jieshao","jieshao");
	add_action("do_jieshao","tuijian");
	add_action("do_choose", "xuanze");
	add_action("do_lingpai","shenqing");
	add_action("read_task", "task");
}			   

int accept_fight(object me)
{
	message_vision("\n������ӥ��ֵش�����$Pһ�ۣ���Ȼ��Ц��������\n", me );
	message_vision("������������·𶼲�����������\n\n", me );
	return 0;
}

int accept_object(object who, object ob )
{
	
	object lingpai;
	string dir1,dir2;
	
	dir1 = dir_random();
	dir2 = to_english( dir1 );
	
	if( who->query("yipin_task/keyname") == "ȡ" && 
		who->query("yipin_task/obname") == ob->query("name") )
	{
		if ( userp( ob ) )
		{
			message_vision("$YEL������ӥ��$P���һ������Һ�Ū�Ϸ�\n$COM", who );
			call_out("kill_stranger",1,who);
			return 0;
		}
		tell_object( who, "$YEL������ӥ��ͷ�����ã�\n$COM");
		YIPIN_D->end_yipin_task("ȡ", who, ob );
		return 1;
	}
	
	if( who->query("yipin_task/keyname") == "��׽" && 
		who->query("yipin_task/obname") == ob->query("name") )
	{
		if ( userp( ob ) )
		{
			message_vision("$YEL������ӥ��$P���һ������Һ�Ū�Ϸ�\n$COM", who );
			call_out("kill_stranger",1,who);
			return 0;
		}
		if ( ( who->query("mud_age") - who->query("lnwm/yipin/�η�") ) < 600 )
		{
			tell_object( who, "������ӥ������һ�ۣ��Ҹող�������ѷ����͵�����ȥ��ô��\n");
			return 0;	   
		}
		tell_object( who, "$YEL������ӥ��ͷ�����ɵĲ���\n$COM");
		tell_object( who, "$YEL������������ӣ��ѷ����͵������η�ȥ��\n$COM");
		lingpai=new(__DIR__ "obj/laofangling");
		lingpai->set("������",who->query("id") );
		lingpai->move(who);
		tell_object( who,"������ӥ��������˵������һ����"+dir1+"�ߵ����ӾͿɽ�����¡�\n");
		who->set_temp("lnwm/enter_yipin/��",dir1);
		who->set_temp("lnwm/enter_yipin/Ӣ",dir2);	 
		who->set("lnwm/yipin/�η�", who->query("mud_age") );					
		return 0;
	}
	if ( ob->query("id") != "rutang xin" )
	{
		message_vision("������ӥ��ֵؿ���$Pһ�ۣ�˵������������ʲô��\n", who );
		return 0;
	}
	else
	{
		if ( ob->query("������") == "��ϸ" )
		{
			message_vision("������ӥֻ����һ����Ƥ���ͳ�$P��Ц��һ�������Ǹ�û�õĶ�����\n���ø����ڽ����Ķ�����˭���ģ������ˣ����£�\n", who );
			call_out("kill_stranger",1,who);
			return 1;
		}
		if ( who->IsMemberOf("yipin") )
		{
			tell_object( who, "���Ѿ���һƷ�õ����ˡ�\n");
			return 0;
		}
		if ( ob->query("������") != who->query("id") )
		{
			message_vision("������ӥ���˷����ţ�Ȼ�����´�����$Pһ������Ȼ��Ц��һ����\n", who );
			message_vision("�����Ǻ������ڽ������ֽ������ô�����������ˣ������£���\n", who );
			call_out("kill_stranger",1,who );
			return 1;		
		}
		else
		{
			message_vision("������ӥ�������ţ��ִ�����$P���ۡ����˵�ͷ��\n", who );
			message_vision("�ã����ǳ��ڽ����Ƽ��������ˡ�\n", who );
			call_out("start_rutang",1,who );
			return 1;
		}
	}
}

int do_shengji()
{
	object me = this_player();
	int max_score, i, jibie;
	
	max_score = 1;
	i = 1;
	if( !me->IsMemberOf( "yipin" ) )
	{
		command( "say �����Ķ����ģ�������һƷ��û�й�ϵ��" );
		return 1;
	}
	if ( me->query("lnwm/yipin/Ҫ������") > 10 )
	{
		message_vision("������ӥͻȻ����$Nһ�ۣ������ǵڼ������������������ˣ��ߣ�\n", me );
		me->AddZuzhiScore("yipin", -50);
		me->delete("lnwm/yipin/Ҫ������");
		return 1;
	}
	jibie = me->ZuzhiTouxianJibie( "yipin" );
	while( i <= jibie )
	{
		max_score = max_score * 2;
		i++;
	}
	max_score = max_score * 200+ 1000*( jibie+1 ); // here refined by lnwm 
	//  �����Ļ���������Ҫ��score�� 1200(ɱ��), 2400(ɱ��ͳ��), 3800(ָ��ʹ), 5600(���ܹ�),  
	if( me->ZuzhiScore("yipin") >= max_score )
		//	   && me->query( "yipin_tang_quest_done" ) > jibie )
	{			   
		command( "say �ã������ʱ��ɵĲ������Ե�������Ҫ��ְ��" );
		//me->add( "yipin/zuzhi_dengji_num", 1 );
		me->IncreaseZuzhiTouxian( "yipin", 1 );
		message_vision( "ף��$N��Ϊ" + me->ZuzhiName( "yipin" ) + 
			me->ZuzhiTouxian( "yipin" ) + "!!\n", me  );
		LOG_D->do_log( me, sprintf( "����%s�л�ý�������Ϊһ��%s��", me->ZuzhiName( "yipin" ),
			me->ZuzhiTouxian( "yipin" ) ) );
		command( "say ��������Ŭ������" );
		me->delete("lnwm/yipin/Ҫ������");
		me->delete("lnwm/yipin/��������");
		return 1;
	}
	message_vision("������ӥ����ؿ���$Nһ�ۣ������û����Զ����Ҫ�������������������Ҫ��\n", me );
	me->add("lnwm/yipin/Ҫ������",1);
	return 1;	
}	

int start_rutang( object me )
{
	object ob = this_object();
	
	message_vision( GRN @LONG
		
		$N��$n˵:
		
		�뱾�õĵ���һ��ʼ�ͱ���ѡ��һ�����ü��롣
		�����ѡ��(xuanze)�������á��͡������á��е�һ�����������á��Ǳ�����ɱ
		��Ч���ķ��ã����е���Ӧ����Ҫ�����Σ�����ú��Ҵ��Ĺ�֮�ˣ��������á�
		�Ǳ������Ե�ϸ��Ч���ķ��ã����е���Ҫ���ӷԸ���̽�����ڱ��ú��Ҵ��Ĺ�
		���鱨������ѫ׿�������Ĺ����ĵ��Ӷ��л�����Ǩ���Ƚ��������������á���
		�������տ��������������󽫾�����ְλ���ٳ��мӣ��������á��ĵ���������
		�������������������ĵ�λ���ǿ���һ�ԾŶ���λ���˳�������ô�����������
		û�У�
		
		LONG $COM, ob, me );
	me->set_temp("pending/һƷ/can_choose", 1);
	return 1;
}

int do_choose(string arg)
{
	object me;
	me = this_player();
	if( !(me->query_temp("pending/һƷ/can_choose" )) )
		return 0;
	if( !arg ||
		( arg != "������" && arg != "������" && arg != "xuanyangtang" && arg != "xuancaitang" ) )
		return 0;
	me->delete_temp( "pending/һƷ/can_choose" );
	if( arg == "������" || arg == "xuanyangtang" )
	{
		message_vision( "$CYN$N˵��������ѡ�����ðɡ�\n$COM", me );
		message_vision( "$YEL\n
			$N˵�����ã����Ҿ�������롸�����á�������������ù棬Ч�Ҵ��ģ�\n
			$n���ڵأ��������ˡ�����������ͷ��\n
			$COM", this_object(), me );
			tell_object( me, "��ϲ���Ϊ���ġ�һƷ�á������������á�ͽ�ڣ�\n" );
		me->JoinZuzhi("yipin","ͽ��","������");
		me->set( "zuzhi/yipin_tang/zuzhi_dengji", "ͽ��" );
		me->set( "yipin/zuzhi_dengji_num", 0 );
		return 1;
	}
	message_vision( "$CYN$N˵��������ѡ�����ðɡ�\n$COM", me );
	message_vision( "$YEL\n
		$N˵�����ã����Ҿ�������롸�����á�������������ù棬Ч�Ҵ��ģ�\n
		$n���ڵأ��������ˡ�����������ͷ��\n
		$COM", this_object(), me );
		tell_object( me, "��ϲ���Ϊ���ġ�һƷ�á������������á�ͽ�ڣ�\n" );
	me->JoinZuzhi("yipin","ͽ��","������");
	me->SetZuzhiScore("yipin",0);
	return 1;
}

int try_rutang()
{
	object me = this_player();
	
	if ( me->IsMemberOf("yipin") )
	{
		message_vision("$P�������ӥ���֣���ְ�������ˣ�\n",me);
		return 1;
	}
	
	if ( !( me->query("lnwm/yipin_tang/������1") ) )
	{
		message_vision("������ӥ�����һ������˭���������ģ�\n", me );
		return 1;
	}
	else if ( !( me->query("lnwm/yipin_tang/������2") ) )
	{
		message_vision("������ӥ΢΢���˵�ͷ���㻹��Ҫ��һ���˵��Ƽ���\n", me );
		return 1;
	}
	else
	{
		message_vision("������ӥ���˵�ͷ���ü������Ƽ�����������ðɡ�\n", me );
		me->delete("lnwm/yipin_tang/������1");
		me->delete("lnwm/yipin_tang/������2");
		call_out("start_rutang",1,me );
		return 1;
	}
}

int do_jieshao( string arg )
{
	object me, *inv;
	int i;
	
	me = this_player();
	
	if ( !arg )
	{
		tell_object( me, "��Ҫ����˭��\n");
		return 1;
	}
	
	if ( !me->IsMemberOf("yipin") )
	{
		message_vision("������ӥ΢΢һЦ����$P˵�������˰ɣ�\n",me);
		return 1;
	}
	
	if ( arg == me->query("id") )
	{
		tell_object(me,"����˰ɣ��Ƽ����Լ�������Ϊ����ë��ѽ��\n");
		return 1;
	}
	
	if ( me->ZuzhiScore("yipin") < 4000 )
	{
		message_vision("������ӥ��$P΢΢һЦ����Ա��õ��ҳ��л���������û���Ƽ����ʸ�\n", me);
		return 1;
	}
	else
	{
		inv = all_inventory( environment(this_object() ) );
		
		for ( i=0; i < sizeof(inv); i++ )
		{
			if ( !userp(inv[i]) ) continue;
			if ( inv[i]->query("id") == arg )  
			{
				if ( inv[i]->IsMemberOf("yipin"))
				{
					message_vision("������ӥ�����������Ǳ������£������Ƽ��ˡ�\n",me);
					return 1;
				}
				
				if ( !(inv[i]->query("lnwm/yipin_tang/������1")) )
				{
					message_vision("$N�������ӥ�Ƽ�$n��\n",me,inv[i]);
					message_vision("������ӥ��$P���ͷ����֪���ˡ�\n",me);
					inv[i]->set("lnwm/yipin_tang/������1", me->query("id") );
					return 1;
				}
				else if ( (inv[i]->query("lnwm/yipin_tang/������1")) != (me->query("id")) )
				{
					message_vision("$N�������ӥ�Ƽ�$n��\n",me,inv[i]);
					message_vision("������ӥ΢Ц�ſ���$P�����ѵõ������˵��Ƽ��ˡ�\n",inv[i]);
					inv[i]->set("lnwm/yipin_tang/������2", me->query("id") );
					return 1;
				} 
				tell_object( me, "���Ѿ��Ƽ���������ˡ�\n");
				return 1;
			}
		}
		tell_object( me, "��Ҫ���ܵ��˲������\n");
		return 1;
	}
}

int refuse_killing( object me )
{
	me->apply_condition("kill_yipin",500);
	message_vision("������ӥ��Цһ��������������������Ұ����ò��ͷ��ˣ�\n", me );
	call_out("kill_stranger",1,me);
	return 1;
}

int kill_stranger( object me )
{
	int i;
	object *inv;
	
	inv = all_inventory( environment(this_object()) );
	
	message_vision("$CYN\nֻ��������ӥ���ڰ���һ�ģ�$N���µĵ��澹�ƶ�����������\n$COM", me );
	call_out("kill_stranger1",3,me );
	
	message_vision("\n������ӥ��Ц�ţ����˻�Ĳ��ͷ��ˣ������ˣ����¡�\n",me );
	
	for(i = 1; i < sizeof(inv); i++)
	{
		if ( !userp( inv[i] )
			&&  inv[i] != this_object() 
			&& inv[i]->IsMemberOf("yipin")
			&& inv[i] != me )
		{
			inv[i]->kill_ob(me);
			me->fight_ob( inv[i] );
		}
	}
	return 0;
}

int kill_stranger1( object me )
{
	if( !present( me, environment( this_object() ) ) )
		return 0;
	
	if( me->query("combat_exp" ) < 50000 )
	{
		message_vision("$CYN$N����һ�������Ȼ����һ�����棬$Nһ����ͷ���˽�ȥ��\n$COM", me );
		me->unconcious();
		me->move( "/d/zuzhi/yipin_tang/dixia/laofang3" );
		return 0;
	}
	else if( random(2) )
	{
		message_vision("$CYN$N���Ʋ��һ������������ˡ���\n$COM", me );
		me->move( "/d/zuzhi/yipin_tang/yongdao3" );
		me->set_temp_marks("lnwm/yipin_tang/�ӳ�",1);
		return 0;
	}
	else
	{
		message_vision("$CYN$N���Ʋ����������ӣ����ſ��ѱ���ס���������ڽ��´򿪣�%Nһ����ͷ���˽�ȥ��\n$COM", me );
		me->unconcious();
		me->move( "/d/zuzhi/yipin_tang/dixia/laofang3" );
		return 0;
	}
}

int do_lingpai( string arg )
{
	object me, lingpai;
	string dir1,dir2;
	
	dir1 = dir_random();
	dir2 = to_english( dir1 );
	
	me = this_player();
	
	if( !me->IsMemberOf("yipin") )
		return notify_fail("�㻹û�м���һƷ�á�\n");
	
	if( !arg)
		return notify_fail("������������ӥ����������(xuanwuling),\n������(xuanyangling)��������(xuanyunling)��������(xuancailing)��\n");
	
	if( arg == "������" || arg == "xuanwuling" )
	{
		//xuanwuling �� $YEL ��
		if( me->ZuzhiScore("yipin") <= 500 )
		{
			tell_object( me, "$CYN������ӥ΢һ�����㻹����Ϊ���ö���Щ������Ȼ����̸����¡�\n$COM" );
			return 1;
		}
		if( me->query("lnwm/yipin/��������") < ( 4 << me->ZuzhiTouxianJibie("yipin") ) )
		{
			tell_object( me, "$YEL\n������ӥ��ͷ�������������������ְλ�ϵ�" + (me->query("lnwm/yipin/��������")+1) + "�����������\n\n$COM",   );
			tell_object( me, "$CYN������ӥת������һ�����ƣ�������д�˼����֣�Ȼ��֣�ؽ����㡣\n$COM" );
			tell_object( me, "$GRN\n������ӥ�����������˵�������ý����������ǵİ�����--��ͼ��\n$COM" );
			tell_object( me, "$GRN���ڽ�����˵�������֣���Ȼ���˽�����ɽ��\n$COM" );
			me->add("lnwm/yipin/��������", 1 );
			lingpai=new(__DIR__ "obj/xuanwuling");
			lingpai->set("������",me->query("id") );
			lingpai->move(me);
			return 1;
		}
		else
		{
			message_vision( "$RED\n������ӥ˫üһ������������������ʲô����Ա��õĹ����㹻��ô�����ߣ�\n\n$COM", me );
			return 1; 
		}
	}
	
	if( arg == "������" || arg == "xuanyangling" )
	{
		if ( ( me->query("mud_age") - me->query("lnwm/yipin/������")  ) < 600 )
		{
			tell_object( me, "������ӥ������һ�ۣ��㲻�ǸողŴ�����������һ��������ô?\n");
			return 1;	   
		} 
		if ( me->query("lnwm/yipin	ask/������" ) )
		{
			lingpai=new(__DIR__ "obj/xuanyangling");
			lingpai->set("������",me->query("id") );
			lingpai->move(me);
			tell_object( me,"������ӥ��������˵������һ����"+dir1+"�ߵ����ӾͿɽ�����¡�\n");
			me->set_temp("lnwm/enter_yipin/��",dir1);
			me->set_temp("lnwm/enter_yipin/Ӣ",dir2); 
			me->set("lnwm/yipin/������", me->query("mud_age") );
			return 1;
		}
		else
		{
			return notify_fail( "��Ŀǰû�����������Ȩ����\n");
		}
	}
	if( arg == "������" || arg == "xuancailing" )
	{
		if ( (  me->query("mud_age") - me->query("lnwm/yipin/������")  ) < 600 )
		{
			tell_object( me, "������ӥ������һ�ۣ��㲻�ǸողŴ�����������һ��������ô?\n" );
			return 1;	   
		}
		if ( me->query("lnwm/yipin	ask/��ҩ" ) )
		{
			lingpai=new(__DIR__ "obj/xuancailing");
			lingpai->set("������",me->query("id") );
			lingpai->move(me);
			tell_object( me,"������ӥ��������˵������һ����"+dir1+"�ߵ����ӾͿɽ�����¡�\n");
			me->set_temp("lnwm/enter_yipin/��",dir1);
			me->set_temp("lnwm/enter_yipin/Ӣ",dir2);	   
			me->set("lnwm/yipin/������", me->query("mud_age") );					
			return 1;
		}
		else
		{
			return notify_fail( "��Ŀǰû�����������Ȩ����\n");
		}
	}
	if( arg == "������" || arg == "xuanyunling" )
	{
		if ( ( me->query("mud_age") - me->query("lnwm/yipin/������") ) < 600 )
		{
			tell_object( me, "������ӥ������һ�ۣ��㲻�ǸողŴ�����������һ��������ô?\n");
			return 1;	   
		}
		if ( me->query("lnwm/yipin	ask/��ҩ" ) )
		{
			lingpai=new(__DIR__ "obj/xuanyunling");
			lingpai->set("������",me->query("id") );
			lingpai->move(me);
			tell_object( me,"������ӥ��������˵������һ����"+dir1+"�ߵ����ӾͿɽ�����¡�\n");
			me->set_temp("lnwm/enter_yipin/��",dir1);
			me->set_temp("lnwm/enter_yipin/Ӣ",dir2);	 
			me->set("lnwm/yipin/������", me->query("mud_age") );					
			return 1;
		}
		else
		{
			return notify_fail( "��Ŀǰû�����������Ȩ����\n");
		}
	}
	return notify_fail("�㲻�����������\n");
}

string dir_random()
{
	string dir;
	int i;
	
	i = random(4);
	dir = "";
	
	switch( i )
	{
	case 0: dir = "��";break;
	case 1: dir = "��";break;
	case 2: dir = "��";break;
	case 3: dir = "��";break;
	}
	return dir;
}

string to_english( string arg )
{
	string dir;
	
	dir = "";
	if( arg == "��" ) dir = "east";
	if( arg == "��" ) dir = "west";
	if( arg == "��" ) dir = "south";
	if( arg == "��" ) dir = $COM"th";
	return dir;
}

int read_task( object me )
{
	string arg;
	int i;
	
	me = this_player();
	
	if( !me->IsMemberOf("yipin") ) return 0;
	
	//  if( arg = me->GetTaskMessage( "yipin" ) )
	if( me->query("yipin_task") )
	{
		tell_object( me, "$RED\n������ӥ��Ц��һ������������񶼲������\n$COM" );
		tell_object( me, "$RED����û�ã�\n$COM" );
		if ( me->ZuzhiScore("yipin") < -500000 )
			return 1;
		if ( me->ZuzhiScore("yipin") < 500 )	
		{
			me->AddZuzhiScore("yipin", -5 );
		}
		else
		{
			i = me->ZuzhiScore("yipin")/100;
			me->AddZuzhiScore("yipin", -i );	
		}
		tell_object( me , me->query("yipin_task	ask_message") );
		return 1;
	}	
	else
	{
		tell_object( me, "$RED\n������ӥ��ֵؿ�����һ�ۣ�����ô���Լ���û��ʹ�����㲻�����\n$COM" );
		me->AddZuzhiScore("yipin", -5 );
		tell_object( me , "\n������û������\n" );
		return 1;
	}
}

int crash( object ob )
{
	destruct( ob );
}
*/
NPC_END;