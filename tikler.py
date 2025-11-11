# Admission Form using Tkinter
# Author: Your Name
# Experiment: Design a User Interface in Python (Admission Form)

import tkinter as tk
from tkinter import messagebox

# Create main window
window = tk.Tk()
window.title("Student Admission Form")
window.geometry("500x700")
window.configure(bg="lightblue")

# Heading
heading = tk.Label(window, text="Admission Form", font=("Arial", 18, "bold"), bg="blue", fg="white")
heading.pack(fill=tk.X, pady=10)

# --- Define Variables ---
name_var = tk.StringVar()
age_var = tk.StringVar()
gender_var = tk.StringVar()
dob_var = tk.StringVar()
email_var = tk.StringVar()
phone_var = tk.StringVar()
course_var = tk.StringVar(value="Select Course")
declaration_var = tk.IntVar()

# --- Form Fields ---

# Name
tk.Label(window, text="Full Name:", font=("Arial", 12), bg="lightblue").pack(pady=5)
tk.Entry(window, textvariable=name_var, width=40).pack()

# Age
tk.Label(window, text="Age:", font=("Arial", 12), bg="lightblue").pack(pady=5)
tk.Entry(window, textvariable=age_var, width=40).pack()

# Gender
tk.Label(window, text="Gender:", font=("Arial", 12), bg="lightblue").pack(pady=5)
gender_frame = tk.Frame(window, bg="lightblue")
gender_frame.pack()
tk.Radiobutton(gender_frame, text="Male", variable=gender_var, value="Male", bg="lightblue").pack(side=tk.LEFT, padx=10)
tk.Radiobutton(gender_frame, text="Female", variable=gender_var, value="Female", bg="lightblue").pack(side=tk.LEFT, padx=10)
tk.Radiobutton(gender_frame, text="Other", variable=gender_var, value="Other", bg="lightblue").pack(side=tk.LEFT, padx=10)

# DOB
tk.Label(window, text="Date of Birth (DD/MM/YYYY):", font=("Arial", 12), bg="lightblue").pack(pady=5)
tk.Entry(window, textvariable=dob_var, width=40).pack()

# Email
tk.Label(window, text="Email ID:", font=("Arial", 12), bg="lightblue").pack(pady=5)
tk.Entry(window, textvariable=email_var, width=40).pack()

# Phone
tk.Label(window, text="Phone Number:", font=("Arial", 12), bg="lightblue").pack(pady=5)
tk.Entry(window, textvariable=phone_var, width=40).pack()

# Address
tk.Label(window, text="Address:", font=("Arial", 12), bg="lightblue").pack(pady=5)
address_text = tk.Text(window, height=4, width=40)
address_text.pack()

# Course Selection
tk.Label(window, text="Select Course:", font=("Arial", 12), bg="lightblue").pack(pady=5)
courses = ["B.Tech", "B.Sc", "B.Com", "BBA", "MBA", "MCA"]
tk.OptionMenu(window, course_var, *courses).pack()

# Declaration
tk.Checkbutton(window, text="I hereby declare that all information is true.",
               variable=declaration_var, bg="lightblue").pack(pady=10)

# --- Button Functions ---
def submit_form():
    name = name_var.get()
    age = age_var.get()
    gender = gender_var.get()
    dob = dob_var.get()
    email = email_var.get()
    phone = phone_var.get()
    address = address_text.get("1.0", "end-1c")
    course = course_var.get()
    declaration = declaration_var.get()

    if not all([name, age, gender, dob, email, phone, address]) or course == "Select Course":
        messagebox.showerror("Error", "Please fill all fields!")
        return
    if declaration == 0:
        messagebox.showwarning("Warning", "Please agree to the declaration!")
        return

    # Display info
    info = f"Name: {name}\nAge: {age}\nGender: {gender}\nDOB: {dob}\nEmail: {email}\nPhone: {phone}\nAddress: {address}\nCourse: {course}"
    messagebox.showinfo("Form Submitted", f"Form Submitted Successfully!\n\n{info}")

def reset_form():
    name_var.set("")
    age_var.set("")
    gender_var.set("")
    dob_var.set("")
    email_var.set("")
    phone_var.set("")
    course_var.set("Select Course")
    declaration_var.set(0)
    address_text.delete("1.0", "end")

# Buttons
tk.Button(window, text="Submit", command=submit_form, bg="green", fg="white", width=15).pack(pady=10)
tk.Button(window, text="Reset", command=reset_form, bg="red", fg="white", width=15).pack(pady=5)
tk.Button(window, text="Exit", command=window.destroy, bg="black", fg="white", width=15).pack(pady=10)

# Run window
window.mainloop()
