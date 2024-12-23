//xunbu.h
//code by zwb
//12-25

NPC_BEGIN(CNpub3_xunbu);

virtual void create()
{
	 static char xunbuname[7][5]={"慕容","西门","公孙","上官","南宫","欧阳","司徒"};

	 set_name(xunbuname[random(7)],"xun bu");

	 set("icon", young_man2);
	 set("gender", "男性" );
     set("age", 25);
     set("str", 45);
     set("cor", 50);
     set("cps", 35);
     set("int", 20);
     set("per", 20);
     set("kar", 15);
     set("long","巡捕个个身手矫健，强盗、山贼无不闻风丧胆。");
     set("status","patrol");
     set("CatchWho",0l);
     set("combat_exp", 500000);
     set("attitude", "heroism");
     set("chat_chance_combat", 40);


     set_inquiry("贿赂","说哪里话来，县太爷清贫廉正，我们作手下的岂能辱没他的名声？收起你的钱吧！");
     set_inquiry("薪水","哎，老爷俸银微薄，我们的年饷自然更少了......");
     set_inquiry("钱","说实在的，我也想要钱。但要是让老爷知道了我收受贿赂不死也得扒层皮");

     set ("chat_chance",99);
/*     set ("chat_msg", ({
                      (:call_out,"patrol",0:),
                      }) );*/
     set("pursuer",1);
     set_skill("blade", 100);
     set_skill("parry", 90);
     set_skill("dodge", 70);

//     direction=GO;
     carry_object("gangdao")->wield();
     carry_object("cloth")->wear();
     add_money(30);
}

virtual char * combat_chat_msg(CChar * player)
{
	switch(random(4))
	{
	case 0:
		return "你想干什么? 还不跟我去县衙受审!?";
	case 1:
		return "大胆! 居然敢当街拒捕! 想造反？";
	case 2:
		return "巡捕手中的刀越砍越快，让你应接不暇。";
	case 3:
		return "别胡闹了，还是乖乖的跟我走吧。";
	}
	return "";
}
/*
void init()
{
object catchwho,you,*npc;
object oldman,start_room;
int i,tmp;
catchwho=query("CatchWho");
you=this_player();
if (query("status")=="patrol")
   {
   if (!is_fighting()&&interactive(you)&&living(you))
      {
        npc=all_inventory(environment());
        i=sizeof(npc);
        while (i--) {
                if (npc[i]->query("id")=="gangster"&&!userp(npc[i]))
                        {
                        say(HIW "今儿是什么日子？\n"+"居然"+
                                npc[i]->query("name")+
                               "也敢在大街上溜哒！" NOR);
                        npc[i]->remove_all_enemy();
                        say("去死吧！！\n");
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        npc[i]->kill_ob(this_object());
                        }
                else if (npc[i]->query("title")=="野羊山寨三寨主"&&!userp(npc[i]))
                        {
                        say(HIR "哼，手下败将！总有一天我们要荡平野羊山寨！\n" NOR);
                        npc[i]->remove_all_enemy();
                        EMOTE_D->do_emote( npc[i],"fear");
                        kill_ob(npc[i]);
                        }
                }
        if (you->query("thief")&&random(10)<7)
           {
           say (HIR "闹了半天原来"+you->query("name")+
                        "是个贼啊! 我走一趟吧!\n" NOR);
           you->add("crime_lv",THIEF);
           you->add("thief",-1);
           if (!you->query("thief")) you->delete("thief");
           catchyou(you);
                return;
           }
        else
            if (you->query("marks/强盗")&&random(10)<9)
               {
               message_vision("$N对着$n喝道：光天化日之下，你居然也敢行凶杀人？
还不与我回去吃板子！\n"
                +"说罢，$N解下铁链套在$n的脖子上。\n",this_object(),you);
                        you->add("crime_lv",ROBBER);
                        you->add("marks/强盗",-1);
                        if (!you->query("marks/强盗")) you->delete("marks/强盗");
                catchyou(you);
                }
        }
   }
else if (query("status")=="catching")
   {
   catchyou(catchwho);
   message_vision(HIR "只见$N突然从腰间解下一条铁链套在$n的脖子上。\n"NOR,
                this_object(),catchwho);
   }
else {
      if (objectp(catchwho=this_object()->query("CatchWho")))
        {
            if (BigWay[file_name(environment())][direction]==0)
                        {
        say("try to patrol\n");
                        start_room=find_object("/d/choyin/yamen.c");
                        oldman=find_object("/d/choyin/npc/judgeman.c");
                        oldman=present(oldman->query("id"),start_room);
                        write(oldman->query("id"));
                        catchwho->move(start_room);
                        move(start_room);
                        say("老爷，人犯已带到，小人巡街去了。\n");
                        set("CatchWho",0);
                        direction=GO;
                        set("status","patrol");
                        move(find_object(query("startroom")+".c"));
                        patrol();
                        call_other(oldman,(:call_out,"settle_lawsuit",catchwho,2:));
                        return;
                        }
                }
        }
//add_action("do_go","go");
//add_action("do_quit","quit");
add_action("accept_bribery","bribe");
}

void patrol()
{
int i,on_way;
object *content,catchwho,start_room,crime,oldman;
string *bigwayname,where,dir;
bigwayname=keys(BigWay);
where=file_name(environment());
write("in patrol\n");
for (i=0;i<sizeof(bigwayname);i++)
    {
    if (where==bigwayname[i])
       {
       on_way=1;
       break;
       }
    else on_way=0;
    }
if (on_way)
   {
   if (this_object()->query("status")=="patrol")
      {
      if (!BigWay[where][direction]) direction=1-direction;
      }
   else if (this_object()->query("status")=="catching")
      {
      catchyou(catchwho);
      message_vision(HIR "只见$N突然从腰间解下一条铁链套在$n的脖子上"NOR,
                        this_object(),catchwho);
      }
   else
      {
        write("here???\n");
         }
  }
else
   {
   content=all_inventory(this_object());
   for (i=0;i<sizeof(content);i++)
       {
       if (content[i]->query("id")=="amulet")
                {
                if (!stringp(dir=content[i]->query("map")[where]))
                        {
                        move(start_room=find_object(query("startroom")+".c"));
                        if (objectp(crime=query("CatchWho")))
                                {
                                if (where==file_name(environment(crime)))
                                        crime->move(start_room);
                                }
                        }
                else mygo(dir);
          break;
          }
  }
  */
NPC_END;